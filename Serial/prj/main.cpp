#include "mainwindow.h"
#include "serialcom.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    getSerialPortInfo();
    initSerialPort();

    return a.exec();
}
