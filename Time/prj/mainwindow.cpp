#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hogehoge()
{
    qDebug() << "QTimer";
}

void MainWindow::on_pushButton_clicked()
{
    auto timer = new QTimer(this);
    timer->setInterval(500);
//    timer->setSingleShot(false);
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),SLOT(hogehoge()));
    timer->start();
}
