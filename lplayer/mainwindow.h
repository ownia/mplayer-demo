#ifndef __MAINWINDOW_H_
#define __MAINWINDOW_H_

#include <QMainWindow>
#include <QProcess>

QT_BEGIN_NAMESPACE
class QString;
class QPushButton;
class QProcess;
class QHBoxLayout;
QT_END_NAMESPACE

class Player;
class QSocketNotifier;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget * parent = 0);
	~MainWindow();

protected:

protected slots:
        void slotPlay(); 		// 播放
        void slotStop(); 		// 停止
        void slotStep(); 		// 步进
        void slotBackward(); 	// 后退
        void slotMute(); // 静音

	void slotOpenFile();

	void slotStarted();
	void slotError(QProcess::ProcessError error);
	void slotFinished(int exitCode, QProcess::ExitStatus exitStatus);
	void slotBackMessage();

        void buttonClicked();

private:
	Player *player;

	QPushButton *openFileButton;
	QPushButton *playButton;
	QPushButton *stopButton;
	QPushButton *stepButton;
	QPushButton *backwardButton;
	QPushButton *muteButton;

	QHBoxLayout *buttonLayout;

	QString currentFileName;

        int m_fd;
        QSocketNotifier* m_notifier;
        bool m_oldButtonsState[6];
};

#endif // __MAINWINDOW_H_
