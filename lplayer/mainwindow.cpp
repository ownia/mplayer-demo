#include <QtGui>

#include "player.h"
#include "mainwindow.h"
#include <qsocketnotifier.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
        setFixedSize(480,240);

        m_fd = ::open("/dev/buttons", O_RDONLY | O_NONBLOCK);
        if (m_fd < 0) {
            QMessageBox::information(this,"Error", "Fail to open /dev/buttons.");
            return;
        }
        memset(m_oldButtonsState, 0, sizeof m_oldButtonsState);
        m_notifier = new QSocketNotifier(m_fd, QSocketNotifier::Read, this);
        connect (m_notifier, SIGNAL(activated(int)), this, SLOT(buttonClicked()));

	openFileButton = new QPushButton(QIcon(tr(":/images/openfile.png")), tr(""));
	connect(openFileButton, SIGNAL(clicked()), this, SLOT(slotOpenFile()));

	playButton = new QPushButton(QIcon(tr(":/images/play.png")), tr(""));
	connect(playButton, SIGNAL(clicked()), this, SLOT(slotPlay()));

	stopButton = new QPushButton(QIcon(tr(":/images/stop.png")), tr(""));
	connect(stopButton, SIGNAL(clicked()), this, SLOT(slotStop()));

	stepButton = new QPushButton(QIcon(tr(":/images/step.png")), tr(""));
        connect(stepButton, SIGNAL(clicked()), this, SLOT(slotStep()));

	backwardButton = new QPushButton(QIcon(tr(":/images/backward.png")), tr(""));
        connect(backwardButton, SIGNAL(clicked()), this, SLOT(slotBackward()));

        muteButton = new QPushButton(QIcon(tr(":/images/mute.png")), tr(""));
        connect(muteButton, SIGNAL(clicked()), this, SLOT(slotMute()));

	buttonLayout = new QHBoxLayout();
	buttonLayout->addWidget(openFileButton);
	buttonLayout->addStretch(1);
	buttonLayout->addWidget(backwardButton);
	buttonLayout->addWidget(playButton);
	buttonLayout->addWidget(stopButton);
	buttonLayout->addWidget(stepButton);
	buttonLayout->addWidget(muteButton);

	player = new Player();
	player->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	connect(player, SIGNAL(started()), this, SLOT(slotStarted()));
	connect(player, SIGNAL(error(QProcess::ProcessError)), this, SLOT(slotError(QProcess::ProcessError)));
	connect(player, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(slotFinished(int, QProcess::ExitStatus)));
	connect(player, SIGNAL(readyReadStandardOutput()), this, SLOT(slotBackMessage()));

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addWidget(player);
	mainLayout->addLayout(buttonLayout);

	QWidget *centralWidget = new QWidget;
	centralWidget->setLayout(mainLayout);

        setFixedSize(480,240);
	setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete m_notifier;
    ::close(m_fd);
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
            player->controlCmd("pause\n");
        }
        if (buffer[1] & 0x01) {
            player->controlCmd("mute 0\n"); //开启静音
        }
        if (buffer[2] & 0x01) {
            player->controlCmd("mute 1\n"); //关闭静音
        }
}


void MainWindow::slotOpenFile()
{
        this->resize(480,240);
	currentFileName = QFileDialog::getOpenFileName(this, tr("打开媒体文件"), tr(""), 
                                        tr("Video files(*.rmvb *.rm *.avi *.wmv *.mkv *.asf *.3gp *.mov *.mp4 *.ogv *.mp3)"));
	if( !currentFileName.isEmpty() )
	{
		player->play(currentFileName);
        }
}

void MainWindow::slotPlay()
{
	if( currentFileName.isEmpty() )
	{
		slotOpenFile();
		playButton->setIcon(QIcon(":/images/pause.png"));
	}
	else
	{
		player->controlCmd("pause\n");	
	}
}

void MainWindow::slotStop()
{
	player->controlCmd("quit\n");
        currentFileName = "";
}

void MainWindow::slotStep()
{
    player->controlCmd("seek 10 0\n");
}
	
void MainWindow::slotBackward()
{
    player->controlCmd("seek -10 0\n");
}

void MainWindow::slotMute()
{
      player->controlCmd("volume 100 1\n");

      player->controlCmd("mute 0\n"); //开启静音
      player->controlCmd("mute 1\n"); //关闭静音
}

void MainWindow::slotStarted()
{
	qDebug() << "lplayer started...";
}

void MainWindow::slotError(QProcess::ProcessError /*error*/)
{

}

void MainWindow::slotFinished(int /*exitCode*/, QProcess::ExitStatus /*exitStatus*/)
{
	//this->showNormal();
	qDebug() << tr("视频播放完毕，循环播放！");
	player->play(currentFileName);
}

void MainWindow::slotBackMessage()
{
}
