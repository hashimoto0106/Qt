#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    qDebug() << qVersion(); //5.12.2
    qDebug() << QT_VERSION; //330754
    qDebug() << QT_VERSION_STR ;    //5.12.2

    qDebug() << QCoreApplication::applicationName();    //"prj"
    qDebug() << QCoreApplication::applicationVersion(); //"0.0.1.0"
    qDebug() << QCoreApplication::applicationPid(); //12360
    qDebug() << QCoreApplication::applicationDirPath(); //"D:/github/Qt/Information/build-prj-Desktop_Qt_5_12_2_MinGW_64_bit-Debug/debug"
    qDebug() << QCoreApplication::applicationFilePath();    //"D:/github/Qt/Information/build-prj-Desktop_Qt_5_12_2_MinGW_64_bit-Debug/debug/prj.exe"

    //OS
    #ifdef Q_OS_WIN32
        qDebug("Windows");
    #endif

    #ifdef Q_OS_MAC
        qDebug("Mac");
    #endif

    #ifdef Q_OS_LINUX
        qDebug("Linux");
    #endif

    //User

    w.show();
    return a.exec();
}
