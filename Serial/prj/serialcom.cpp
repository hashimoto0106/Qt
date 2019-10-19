#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


void getSerialPortInfo(void)
{
    // Example use QSerialPortInfo
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) { //availablePorts()で利用可能なすべてのシリアルポートが取得できる
        qDebug() << "Name        : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        qDebug() << "serialNumber: " << info.serialNumber();
        qDebug() << "systemLocation: " << info.systemLocation();
        qDebug() << "vendorIdentifier: " << info.vendorIdentifier();
        qDebug() << "productIdentifier: " << info.productIdentifier();
        qDebug() << "hasVendorIdentifier: " << info.hasVendorIdentifier();
        qDebug() << "hasProductIdentifier: " << info.hasProductIdentifier();
//        qDebug() << "availablePorts: " << info.availablePorts();  //実行時にエラーとなる
        qDebug() << "standardBaudRates: " << info.standardBaudRates();
        qDebug() << "isBusy: " << info.isBusy();
        qDebug() << "isNull: " << info.isNull();

        // Example use QSerialPort
        QSerialPort serial;
        serial.setPort(info);
        if (serial.open(QIODevice::ReadWrite)){
            serial.close();
        }
    }
}


//https://qiita.com/shun_ito/items/7ac018ba8967a38d6d68
//void initSerialPort(void)
//{
//    _serialPort->setPortName( QString( "COM5" ) );

//    // baudRate,dataBits,parity,stopBits:
//    // Arduinoのスケッチで指定したものと同じ数値を指定する
//    _serialPort->setBaudRate( QSerialPort::Baud115200 );
//    // ちなみに以下はArduinoのスケッチでSerial.beginの第2引数を省略した時の値
//    _serialPort->setDataBits( QSerialPort::Data8 );
//    _serialPort->setParity(   QSerialPort::NoParity );
//    _serialPort->setStopBits( QSerialPort::OneStop );

//    if ( _serialPort->open( QIODevice::ReadOnly ) )
//    {
//        connect( _serialPort, &QSerialPort::readyRead,
//                 this,        &MainWindow::printData );
//    }
//    else
//    {
//        qDebug() << "Couldn't open the port [COM4].";
//    }
//}


//https://garberas.com/archives/1619
//void initSerialPort(void)
//{
//    port = new QSerialPort(this);

//    // シリアルポートを直接打った
//    port->setPortName(QString("COM5"));

//    port->setBaudRate(QSerialPort::Baud38400);
//    port->setDataBits(QSerialPort::Data8);
//    port->setParity(QSerialPort::NoParity);
//    port->setStopBits(QSerialPort::OneStop);

//    if ( port->open(QIODevice::ReadWrite) )
//    {
//        // readしたときに関数を呼ぶ
//        connect(port, &QSerialPort::readyRead, this, &MainWindow::printData);
//    } else {
//        qDebug() << "Couldn't open the port.\n";
//    }
//}
