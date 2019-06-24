#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

class MainWindow:public QWidget
{
    Q_OBJECT
public:
    void play(QString fileName);
      MainWindow(QWidget *parent = 0);

private slots:
    void next();
    void prev();
    void pause();
    void stop();
    void setSpeed();
    void dataRecieve();
    void addItem();
    void delItem();
    void current(int);
    void changeVolume(int);
    void playListItem(QListWidgetItem *);
    void buttonClicked();
    void exit();


private:
    QLabel *playLabel;
    QLabel *timeLabel;
    QLabel *percentLabel;
    QLabel *voiceLabel;
    QLabel *volumeLabel;

    QFrame *ctlFrame;
    QPushButton *playBtn;
    QPushButton *stopBtn;
    QPushButton *prevBtn;
    QPushButton *nextBtn;
    QPushButton *speedBtn;

    QSlider *currentlBar;
    QSlider *volumeSlider;

    QListWidget *playList;
    QPushButton *addBtn;
    QPushButton *delBtn;

    QProcess *p;
    QString currentStr;
    QString currentPercent;
    QString totalTime;
    QString fileName;

    int m_fd;
    int isPlay;
    QSocketNotifier* m_notifier;
    bool m_oldButtonsState[6];

    QPushButton *exitBtn;
};

#endif // MAINWINDOW_H
