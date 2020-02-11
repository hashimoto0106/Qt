#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    qDebug() << "qVersion" << qVersion(); //5.12.2
    qDebug() << "QT_VERSION" << QT_VERSION; //330754
    qDebug() << "QT_VERSION_STR" << QT_VERSION_STR ;    //5.12.2

    qDebug() << "applicationName" << QCoreApplication::applicationName();    //"prj"
    qDebug() << "applicationVersion" << QCoreApplication::applicationVersion(); //"0.0.1.0"
    qDebug() << "applicationPid" << QCoreApplication::applicationPid(); //12360
    qDebug() << "applicationDirPath" << QCoreApplication::applicationDirPath(); //"D:/github/Qt/Information/build-prj-Desktop_Qt_5_12_2_MinGW_64_bit-Debug/debug"
    qDebug() << "applicationFilePath" << QCoreApplication::applicationFilePath();    //"D:/github/Qt/Information/build-prj-Desktop_Qt_5_12_2_MinGW_64_bit-Debug/debug/prj.exe"
    qDebug() << "organizationDomain" << QCoreApplication::organizationDomain();    //""
    qDebug() << "organizationName" << QCoreApplication::organizationName(); //""

//    qDebug() << VERSION ;
//    qDebug() << QMAKE_TARGET_COMPANY ;
//    qDebug() << QCoreApplication::QMAKE_TARGET_COMPANY ;
	
	
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
