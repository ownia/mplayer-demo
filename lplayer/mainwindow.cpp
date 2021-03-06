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

    // qdb->addDatabase("QSQLITE");
    // qdb->setDatabaseName("./list.db");

    /*
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("/opt/test.db");
    if (!m_db.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }
    */



    sqlshow0 = new QLabel(this);
    sqlshow0->setGeometry(QRect(0, 0, 200, 100));

    QFont ft;
    ft.setPointSize(10);

    playLabel = new QLabel(this);
    playLabel->setGeometry(QRect(0, 0, 368, 207));

    ctlFrame = new QFrame(this);
    ctlFrame->setGeometry(QRect(5, 212, 470, 55));
    ctlFrame->setFrameShape(QFrame::StyledPanel);
    ctlFrame->setFrameShadow(QFrame::Raised);

    currentlBar = new QSlider(ctlFrame);
    currentlBar->setGeometry(QRect(10, 0, 335, 18));
    currentlBar->setOrientation(Qt::Horizontal);
    connect(currentlBar, SIGNAL(sliderMoved(int)), this, SLOT(current(int)));

    percentLabel = new QLabel(ctlFrame);
    percentLabel->setGeometry(QRect(350, 1, 40, 14));

    timeLabel = new QLabel(ctlFrame);
    timeLabel->setGeometry(QRect(395, 1, 65, 14));

    stopBtn = new QPushButton(QIcon(":/images/stop.png"), "", ctlFrame);
    stopBtn->setGeometry(QRect(10, 18, 80, 19));
    stopBtn->setEnabled(false);
    connect(stopBtn, SIGNAL(clicked()), this, SLOT(stop()));

    prevBtn = new QPushButton(QIcon(":/images/prev.png"), "", ctlFrame);
    prevBtn->setGeometry(QRect(95, 18, 80, 19));
    connect(prevBtn, SIGNAL(clicked()), this, SLOT(prev()));

    playBtn = new QPushButton(QIcon(":/images/play.png"), "", ctlFrame);
    playBtn->setGeometry(QRect(180, 18, 80, 19));
    playBtn->setEnabled(false);
    connect(playBtn, SIGNAL(clicked()), this, SLOT(pause()));

    nextBtn = new QPushButton(QIcon(":/images/next.png"), "", ctlFrame);
    nextBtn->setGeometry(QRect(265, 18, 80, 19));
    connect(nextBtn, SIGNAL(clicked()), this, SLOT(next()));

    speedBtn = new QPushButton(QIcon(":/images/speed.png"), "", ctlFrame);
    speedBtn->setGeometry(QRect(350, 18, 110, 19));
    connect(speedBtn, SIGNAL(clicked()), this, SLOT(setSpeed()));

    exitBtn = new QPushButton(QIcon(":/images/exit.png"), "", this);
    exitBtn->setGeometry(QRect(426, 187, 20, 20));
    connect(exitBtn, SIGNAL(clicked()), this, SLOT(exit()));

    listLabel = new QLabel(this);
    listLabel->setFont(ft);
    listLabel->setText(tr("欧阳炜钊"));
    listLabel->setGeometry(373, 4, 102, 15);

    listLabel = new QLabel(this);
    listLabel->setFont(ft);
    listLabel->setText(tr("王雨"));
    listLabel->setGeometry(373, 21, 102, 15);

    voiceLabel = new QLabel(ctlFrame);
    voiceLabel->setPixmap(QPixmap(":/images/voice.png"));
    voiceLabel->setGeometry(QRect(10, 37, 19, 16));
    voiceLabel->setScaledContents(true);

    volumeSlider = new QSlider(ctlFrame);
    volumeSlider->setGeometry(QRect(33, 37, 357, 18));
    volumeSlider->setOrientation(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(100);
    volumeSlider->setEnabled(false);
    connect(volumeSlider, SIGNAL(sliderMoved(int)), this, SLOT(changeVolume(int)));

    volumeLabel = new QLabel(ctlFrame);
    volumeLabel->setGeometry(QRect(395, 38, 65, 14));
    volumeLabel->setText(QString::number(100));

    playList = new QListWidget(this);
    playList->setGeometry(QRect(373, 40, 102, 142));
    connect(playList, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(playListItem(QListWidgetItem *)));

    addBtn = new QPushButton(QIcon(":/images/add.png"), "", this);
    addBtn->setGeometry(QRect(378, 187, 20, 20));
    addBtn->setStyleSheet("border-style:none");
    connect(addBtn, SIGNAL(clicked()), this, SLOT(addItem()));

    delBtn = new QPushButton(QIcon(":/images/remove.png"), "", this);
    delBtn->setGeometry(QRect(450, 187, 20, 20));
    delBtn->setStyleSheet("border-style:none");
    connect(delBtn, SIGNAL(clicked()), this, SLOT(delItem()));

    sqlBtn = new QPushButton(QIcon(":/images/sql.png"), "", this);
    sqlBtn->setGeometry(QRect(402, 187, 20, 20));
    connect(sqlBtn, SIGNAL(clicked()), this, SLOT(sql_list()));
}

void MainWindow::exit()
{
    if(p!=NULL) {
        p->write("quit\n");
        p->kill();
    }
    p=NULL;
    sqlite3_close(db);
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
            p->write(QString("mute 1\n").toUtf8());
        }
        if (buffer[1] & 0x01) {
            p->write(QString("mute 0\n").toUtf8());
        }
        if (buffer[2] & 0x01) {
            p->write(QString("seek 10\n").toUtf8());
        }
        if (buffer[3] & 0x01) {
            p->write(QString("seek -10\n").toUtf8());
        }
}

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

void MainWindow::addItem()
{
    // QFileDialog *filedialog = new QFileDialog(this);
    // filedialog->setWindowTitle(tr("choose file"));
    // filedialog->setAcceptMode(QFileDialog::AcceptOpen);
    // filedialog->setViewMode(QFileDialog::List);
    // filedialog->setGeometry(0, 0, 480, 272);
    // filedialog->setDirectory(".");
    // filedialog->setFilter(tr("movie/song (*.mp4 *.mp3)"));
    // filedialog->setFileMode(QFileDialog::ExistingFiles);
    // QStringList fileNames;
    // filedialog->setHistory(fileNames);

    QFileDialog dialog(this, "choose file", "", "movie/song (*.mp4 *.wmv *.mp3);;all files (*.*)");
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setGeometry(QRect(0, 0, 480, 272));
    QStringList fileNames;
    // QSqlQuery sql_query;
    if (dialog.exec()) {
        fileNames = dialog.selectedFiles();
        playList->addItems(fileNames);
        // sql_query.exec("SELECT MAX(ID) FROM list;");
        // int id = sql_query.value(0).toInt() + 1;
        // QString filename = playList->currentItem()->text();
        // QString list = "INSERT INFO list VALUES (" + QString::number(id) + ", " + filename + ")";
        // sql_query.exec(list);
    }
}

void MainWindow::delItem()
{
    if(playList->currentRow() == -1)
        QMessageBox::warning(this, "note", "not select or playlist is null", QMessageBox::Yes);
    else
        playList->takeItem(playList->currentRow());
}

void MainWindow::playListItem(QListWidgetItem *item)
{
    play(item->text());
    isPlay = 0;
    playBtn->setIcon(QIcon(":/images/pause.png"));
}

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
    args << "368";
    args << "-y";
    args << "207";
    args << fileName;
    p->start(tr("/usr/local/bin/mplayer"), args);

    isPlay = 1;
    playBtn->setEnabled(true);
    stopBtn->setEnabled(true);
    volumeSlider->setEnabled(true);

    timeLabel->show();
    percentLabel->show();
}

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

void MainWindow::changeVolume(int v)
{
    volumeLabel->setText(QString::number(v));
    p->write(QString("volume " + QString::number(v) + " 2\n").toUtf8());
}

void MainWindow::setSpeed()
{
    QEventLoop loop;
    QTimer::singleShot(10, &loop, SLOT(quit()));
    loop.exec();
    double speed=QInputDialog::getDouble(this, "set speed", "compare with nomal speed");
    if(speed > 0)
        p->write(QString("speed_set " + QString::number(speed) + " 2\n").toUtf8());
    loop.exec();
}

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

void MainWindow::current(int value)
{
    p->write(QString("seek " + QString::number(value) + " 2\n").toUtf8());
}

void MainWindow::sql_list()
{
    // int ret;
    // char *str;
    // ret = sqlite3_open("./list.db", &db);
    // QString n = "SELECT MAX(ID) FROM list";
    // const char *sql = n.toAscii().constData();
    // value = sqlite3_exec(db, sql, searchId, NULL, &str);
    // int id = value + 1;
    // QString filename = playList->currentItem()->text();
    // QString list = "INSERT INFO list VALUES (1, " + filename + ")";
    // const char *sql = list.toAscii().constData();
    // sqlite3_exec(db, sql, 0, 0, &str);

    /* --correct code--
    bool success = false;
    QString name = playList->currentItem()->text();
    QSqlQuery query;
    query.prepare("INSERT INTO people (name) VALUES (:name)");
    query.bindValue(":name", name);
    if(query.exec())
    {
        success = true;
    }
    else
    {
         qDebug() << "addPerson error:  "
                  << query.lastError();
    }
    */

    /*
    QSqlQuery query("SELECT * FROM people");
    // int columnNum = query.record().count();
    int id = query.value(0).toInt();
    qDebug() << QString::number(id);
    QString name = query.value(1).toString();
    qDebug() << name;
    sqlshow->setText("ok.");
    QMessageBox::information(this, "sqlite", QString::number(id) + " " + name + "\n", QMessageBox::Yes);
    */

    int result = sqlite3_open("/opt/test.db", &db);
    if(result != SQLITE_OK) {
        qDebug() << "open database failed.";
    } else {
        qDebug() << "open database succeed.";
    }
    char * errmsg = NULL;
    char **dbResult;
    int nRow, nColumn;
    int i, j, index;

    // QString filename = playList->currentItem()->text();
    // QString list = "insert into people VALUES (" + filename + ")";
    // QByteArray data = list.toLatin1();
    // const char * file = data.data();
    // result = sqlite3_exec( db, file, 0, 0, &errmsg);
    result = sqlite3_get_table( db, "select * from people", &dbResult, &nRow,&nColumn, &errmsg );
    if( SQLITE_OK == result )
    {
        index = nColumn;
        qDebug() << QString::number(index);
        sqlshow0->setText(QString::number(index) + " files\n");
        for( i = 0; i < nRow ; i++ ) {
            qDebug() << QString::number(i + 1);
            for( j = 0 ; j < nColumn; j++ ) {
                qDebug() << dbResult[j];
                qDebug() << dbResult[index];
                QString text = dbResult[j];
                QString sqlindex = dbResult[index];
                QMessageBox::information(this, "sqlite", text + " \n" + sqlindex + "\n", QMessageBox::Yes);
                ++index;
            }
        }
        qDebug() << "-------\n";
    }
    sqlite3_free_table(dbResult);
    // sqlite3_exec(db,"select * from people", LoadMyInfo, NULL, errmsg);
}

/*
int LoadMyInfo( void * para, int n_column, char ** column_value, char ** column_name )
{
    int i;
    qDebug() << QString::number(n_column);
    for( i = 0 ; i < n_column; i ++ )
    {
        qDebug() << column_value[i];
    }
    return 0;
}
*/
