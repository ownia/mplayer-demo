#include <QtGui>

#include "player.h"

Player::Player(QWidget * parent)
	: QWidget(parent)
{
	
	renderTarget = new QWidget(this);
	renderTarget->setAttribute(Qt::WA_OpaquePaintEvent);

	mplayerProcess = new QProcess(this);
	connect(mplayerProcess, SIGNAL(started()), this, SIGNAL(started()));
	connect(mplayerProcess, SIGNAL(error(QProcess::ProcessError)), this, SIGNAL(error(QProcess::ProcessError)));
	connect(mplayerProcess, SIGNAL(finished(int, QProcess::ExitStatus)),
			this, SIGNAL(finished(int, QProcess::ExitStatus)));
	connect(mplayerProcess, SIGNAL(readyReadStandardOutput()), this, SIGNAL(readyReadStandardOutput()));
	


}

Player::~Player()
{}
	
void Player::play(const QString &fileName)
{
        QStringList args;
        args << tr("-slave");
        args << "-quiet";
        args << "-zoom";
        //args << "−rootwin";
        //args << "−xy 400";
        args << tr("-wid") << QString::number(renderTarget->winId());
        args << fileName;
        mplayerProcess->start(tr("/usr/local/bin/mplayer"), args);
        emit started();
}

void Player::controlCmd(const QString &cmd)
{
	mplayerProcess->write(cmd.toLatin1());
}

void Player::resizeEvent(QResizeEvent * event)
{
	renderTarget->resize(event->size());
}



//void Player::slotStarted(const QString &fileName)
//{
//	qDebug() << "mplayer started ...";

//}

//void Player::slotError(QProcess::ProcessError /*error*/)
//{
//        qDebug() << "player error.";
//}
//void Player::slotFinished(int /*exitCode*/, QProcess::ExitStatus /*exitStatus*/)
//{
//        qDebug() << "mplayer finished.";
//}

//void Player::slotBackMessage()
//{
//	while( mplayerProcess->canReadLine() )
//	{
//		QString message(mplayerProcess->readLine());
//		// message 即为读取的信息，我们可以根据需要取我们要的信息如：
//		// 文件总时间为：ANS_LENGTH=23.00
//		// 当前时间为：ANS_TIME_POSITION=23.00
//		qDebug() << message;
//	}
//}

