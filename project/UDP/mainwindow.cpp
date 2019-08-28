#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpsocket2.bind(5824);
    connect(ui->pushButton, SIGNAL(clicked()),  this, SLOT(sendDatagram()));
    connect(ui->pushButton_2, SIGNAL(clicked()),  this, SLOT(showMessage()));
    connect(&udpsocket2, SIGNAL(readyRead()), this, SLOT(processPendingDatagram()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendDatagram()
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_1);
    out << QDateTime::currentDateTime() ;

    udpsocket1.writeDatagram(datagram, QHostAddress::LocalHost, 5824);
}

void MainWindow::processPendingDatagram()
{
    QByteArray datagram;

    do
    {
        datagram.resize(udpsocket2.pendingDatagramSize());
        udpsocket2.readDatagram(datagram.data(), datagram.size());
    }
    while (udpsocket2.hasPendingDatagrams());

    QDateTime dateTime;

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_1);
    in >> dateTime;

    message = dateTime.time().toString();
}

void MainWindow::showMessage()
{
    ui->label->setText(message);
}
