#include "mainwindow.h"
#include "findpng.h"
#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    FindPng *mFindPng = new FindPng();
    QThread *thread = new QThread();
    mFindPng->moveToThread(thread);

    QObject::connect(&w, SIGNAL(startButtonClicked(QString)),
                     mFindPng, SLOT(startCheck(QString)));
    QObject::connect(mFindPng, SIGNAL(signalFindPicture(QString)),
                     &w, SLOT(slotFindPicture(QString)));

    w.show();

    thread->start();

    return a.exec();
}
