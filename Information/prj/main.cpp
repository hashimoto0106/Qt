#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    qDebug() << qVersion();
    qDebug() << QT_VERSION;
    qDebug() << QT_VERSION_STR ;

    qDebug() << QCoreApplication::applicationName();
    qDebug() << QCoreApplication::applicationVersion();
    qDebug() << QCoreApplication::applicationPid();
    qDebug() << QCoreApplication::applicationDirPath();
    qDebug() << QCoreApplication::applicationFilePath();

    w.show();
    return a.exec();
}
