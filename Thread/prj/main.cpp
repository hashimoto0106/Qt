#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QThread>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << QThread::currentThreadId() << "QApplication::exec()を実行するスレッドID";
    qDebug() << QThread::currentThread() << "QApplication::exec()を実行するスレッド";

    qDebug() << __FILE__;
    qDebug() << __FUNCTION__;
    qDebug() << __LINE__;

    MainWindow w;
    w.show();

    a.quit();
    qDebug() << "quit";
    QCoreApplication::exit();
    qDebug() << "exit";

    return a.exec();
}
