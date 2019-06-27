#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>

extern "C"
{
    #include "sqlite3.h"
}

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
    void sql_list();


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
    QLabel *listLabel;
    QLabel *listLabel2;
    // QSqlDatabase *qdb;
    sqlite3 *db;
    QPushButton *sqlBtn;
    // QSqlDatabase m_db;
    QLabel *sqlshow0;
    QLabel *sqlshow1;
    QLabel *sqlshow2;
    QLabel *sqlshow3;
    QLabel *sqlshow4;
};

#endif // MAINWINDOW_H
