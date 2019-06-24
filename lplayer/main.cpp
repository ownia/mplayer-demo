#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *mainwindow = new MainWindow;
    mainwindow->showFullScreen();

    return a.exec();
}
