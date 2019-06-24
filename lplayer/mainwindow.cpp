#include "mainwindow.h"
#include <qsocketnotifier.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

MainWindow::MainWindow(QWidget *parent) :QWidget(parent)
{
    resize(480, 272);
    setWindowTitle("player");

    isPlay = 0;
    m_fd = ::open("/dev/buttons", O_RDONLY | O_NONBLOCK);
    if (m_fd < 0) {
        QMessageBox::information(this,"Error", "Fail to open /dev/buttons.");
        return;
    }
    memset(m_oldButtonsState, 0, sizeof m_oldButtonsState);
    m_notifier = new QSocketNotifier(m_fd, QSocketNotifier::Read, this);
    connect (m_notifier, SIGNAL(activated(int)), this, SLOT(buttonClicked()));

    playLabel = new QLabel(this);
    playLabel->setGeometry(QRect(0, 0, 320, 180));

    ctlFrame = new QFrame(this);
    ctlFrame->setGeometry(QRect(5, 210, 470, 55));
    ctlFrame->setFrameShape(QFrame::StyledPanel);
    ctlFrame->setFrameShadow(QFrame::Raised);

    currentlBar = new QSlider(ctlFrame);
    currentlBar->setGeometry(QRect(10, 0, 180, 18));
    currentlBar->setOrientation(Qt::Horizontal);
    connect(currentlBar, SIGNAL(sliderMoved(int)), this, SLOT(current(int)));

    percentLabel = new QLabel(ctlFrame);
    percentLabel->setGeometry(QRect(195, 2, 40, 18));

    timeLabel = new QLabel(ctlFrame);
    timeLabel->setGeometry(QRect(235, 2, 160, 18));

    stopBtn = new QPushButton(QIcon(":/images/stop.png"), "", ctlFrame);
    stopBtn->setGeometry(QRect(10, 18, 40, 18));
    stopBtn->setEnabled(false);
    connect(stopBtn, SIGNAL(clicked()), this, SLOT(stop()));

    prevBtn = new QPushButton(QIcon(":/images/step.png"), "", ctlFrame);
    prevBtn->setGeometry(QRect(60, 18, 40, 18));
    connect(prevBtn, SIGNAL(clicked()), this, SLOT(prev()));

    playBtn = new QPushButton(QIcon(":/images/play.png"), "", ctlFrame);
    playBtn->setGeometry(QRect(110, 18, 55, 18));
    playBtn->setEnabled(false);
    connect(playBtn, SIGNAL(clicked()), this, SLOT(pause()));

    nextBtn = new QPushButton(QIcon(":/images/backward.png"), "", ctlFrame);
    nextBtn->setGeometry(QRect(175, 18, 40, 18));
    connect(nextBtn, SIGNAL(clicked()), this, SLOT(next()));

    speedBtn = new QPushButton(QIcon(":/images/speed.png"), "", ctlFrame);
    speedBtn->setGeometry(QRect(225, 18, 55, 18));
    connect(speedBtn, SIGNAL(clicked()), this, SLOT(setSpeed()));

    exitBtn = new QPushButton(QIcon(":/images/exit.png"), "", this);
    exitBtn->setGeometry(QRect(445, 5, 30, 30));
    connect(exitBtn, SIGNAL(clicked()), this, SLOT(exit()));

    voiceLabel = new QLabel(ctlFrame);
    voiceLabel->setPixmap(QPixmap(":/images/voice.png"));
    voiceLabel->setGeometry(QRect(8, 36, 50, 18));

    volumeSlider = new QSlider(ctlFrame);
    volumeSlider->setGeometry(QRect(80, 36, 300, 18));
    volumeSlider->setOrientation(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(100);
    volumeSlider->setEnabled(false);
    connect(volumeSlider, SIGNAL(sliderMoved(int)), this, SLOT(changeVolume(int)));

    volumeLabel = new QLabel(ctlFrame);
    volumeLabel->setGeometry(QRect(175, 36, 60, 18));
    volumeLabel->setText(QString::number(100));

    playList = new QListWidget(this);
    playList->setGeometry(QRect(370, 40, 100, 150));
    connect(playList, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(playListItem(QListWidgetItem *)));

    addBtn = new QPushButton(QIcon(":/images/add.png"), "", this);
    addBtn->setGeometry(QRect(375, 195, 20, 20));
    addBtn->setStyleSheet("border-style:none");
    connect(addBtn, SIGNAL(clicked()), this, SLOT(addItem()));

    delBtn = new QPushButton(QIcon(":/images/remove.png"), "", this);
    delBtn->setGeometry(QRect(435, 195, 20, 20));
    delBtn->setStyleSheet("border-style:none");
    connect(delBtn, SIGNAL(clicked()), this, SLOT(delItem()));

}

void MainWindow::exit()
{
    QApplication* app;
    app->exit(0);
}

void MainWindow::buttonClicked()
{
        char buffer[8];
        memset(buffer, 0, sizeof buffer);
        ::read(m_fd, buffer, sizeof buffer);
        for (unsigned i = 0; i < sizeof buffer / sizeof buffer[0]; i++) {
            bool wasOn = m_oldButtonsState[i];
            bool isOn = (buffer[i] & 0x01);
            if (wasOn != isOn) {
                m_oldButtonsState[i] = isOn;
                update();
            }
        }
        if (buffer[0] & 0x01) {
            p->write("pause\n");
        }
        if (buffer[1] & 0x01) {
            p->write(QString("mute 1\n").toUtf8());
        }
        if (buffer[2] & 0x01) {
            p->write(QString("mute 0\n").toUtf8());
        }
        if (buffer[3] & 0x01) {
            p->write(QString("exit\n").toUtf8());
        }
}

/*************************************************

Function:next

Description:play the next movie/song

*************************************************/
void MainWindow::next()
{
    if (playList->count() != 0) {
        if(playList->currentRow() == playList->count() - 1)
            playList->setCurrentRow(0);
        else
            playList->setCurrentRow(playList->currentRow() + 1);

        play(playList->currentItem()->text());
        isPlay = 0;
        playBtn->setIcon(QIcon(":/images/pause.png"));
    }
}

/*************************************************

Function:prev

Description:play the previous movie/song

*************************************************/
void MainWindow::prev()
{
    if (playList->count() != 0) {
        if(playList->currentRow() == 0)
            playList->setCurrentRow(playList->count() - 1);
        else
            playList->setCurrentRow(playList->currentRow() - 1);

        play(playList->currentItem()->text());
        isPlay = 0;
        playBtn->setIcon(QIcon(":/images/pause.png"));
    }
}

/*************************************************

Function:addItem

Description:add a item in the playlist

*************************************************/
void MainWindow::addItem()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "choose movie/song", "/", "Movie/Song (*.mp4 *.mp3)");
    if(fileNames.count() != 0)
        playList->addItems(fileNames);
}

/*************************************************

Function:delItem

Description:delete a item in the playlist

*************************************************/
void MainWindow::delItem()
{
    if(playList->currentRow() == -1)
        QMessageBox::warning(this, "note", "not select or playList is null", QMessageBox::Yes);
    else
        playList->takeItem(playList->currentRow());
}

/*************************************************

Function:playListItem

Description:play a item in the playlist

*************************************************/
void MainWindow::playListItem(QListWidgetItem *item)
{
    play(item->text());
    isPlay = 0;
    playBtn->setIcon(QIcon(":/images/pause.png"));
}

/*************************************************

Function:play

Description:call mplayer to play movie/song

*************************************************/

void MainWindow::play(QString fileName)
{
    if (p != NULL)
        p->kill();

    p = new QProcess(this);
    connect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(dataRecieve()));

    QStringList args;
    args << "-slave";
    args << "-quiet";
    args << "-zoom";
    args << "-x";
    args << "320";
    args << "-y";
    args << "180";
    args << fileName;
    p->start(tr("/usr/local/bin/mplayer"), args);

    isPlay = 1;
    playBtn->setEnabled(true);
    stopBtn->setEnabled(true);
    volumeSlider->setEnabled(true);

    timeLabel->show();
    percentLabel->show();
}

/*************************************************

Function:pause

Description:pause a playing movie/song

*************************************************/
void MainWindow::pause()
{
    p->write("pause\n");
    if (isPlay == 1) {
        connect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(dataRecieve()));
        dataRecieve();
        isPlay = 0;
        playBtn->setIcon(QIcon(":/images/pause.png"));
    }
    else {
        disconnect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(dataRecieve()));
        isPlay = 1;
        playBtn->setIcon(QIcon(":/images/play.png"));
    }

}

/*************************************************

Function:stop

Description:stop a playing movie/song

*************************************************/
void MainWindow::stop()
{
    p->kill();
    p = NULL;
    timeLabel->hide();
    percentLabel->hide();
    playLabel->update();

    playBtn->setEnabled(false);
    stopBtn->setEnabled(false);
    volumeSlider->setEnabled(false);
}

/*************************************************

Function:changeVolume

Description:change the volume

*************************************************/
void MainWindow::changeVolume(int v)
{
    volumeLabel->setText(QString::number(v));
    p->write(QString("volume " + QString::number(v) + " 2\n").toUtf8());
}

/*************************************************

Function:setSpeed

Description:set the playing speed

*************************************************/
void MainWindow::setSpeed()
{
    double speed=QInputDialog::getDouble(this, "set speed", "compare with nomal speed");
    if(speed > 0)
        p->write(QString("speed_set " + QString::number(speed) + " 2\n").toUtf8());
}

/*************************************************

Function:dataRecieve

Description:recieve the data from mplayer

*************************************************/
void MainWindow::dataRecieve()
{
    p->write("get_time_length\n");
    p->write("get_time_pos\n");
    p->write("get_percent_pos\n");

    while (p->canReadLine()) {
        QByteArray b = p->readLine();
        b.replace(QByteArray("\n"), QByteArray(""));
        QString s(b);

        if (b.startsWith("ANS_TIME_POSITION")) {
            currentStr = s.mid(18);
            timeLabel->setText(currentStr + "s");
            currentlBar->setValue(s.mid(18).toFloat());
        }
        else if (b.startsWith("ANS_LENGTH")) {
            totalTime = s.mid(11);
            currentlBar->setRange(0, s.mid(11).toFloat());
        }
        else if(b.startsWith("ANS_PERCENT_POSITION")) {
            currentPercent = s.mid(21);
            percentLabel->setText(currentPercent + "%");
        }
    }

}

/*************************************************

Function:current

Description:get the current process from mplayer

*************************************************/

void MainWindow::current(int value)
{
    p->write(QString("seek " + QString::number(value) + " 2\n").toUtf8());
}
