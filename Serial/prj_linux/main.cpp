#include "mainwindow.h"

#include <QApplication>
#include <qextserialport.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    const char data[]= "e";
    QextSerialPort * port = new QextSerialPort("/dev/ttyUSB0");

    port->setBaudRate(BAUD9600);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
    port->setTimeout(0);
    bool res = false;
    res = port->open(QIODevice::ReadWrite | QIODevice::Unbuffered);

    if(res)
    {
        qDebug("Opened");
        qDebug(data);
        int i = port->write(data, sizeof(data));
    }
    else
    {
        qDebug("Failed to connect");
    }

    w.show();
    return a.exec();
}
