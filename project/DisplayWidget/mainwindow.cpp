#include "mainwindow.h"
#include "ui_mainwindow.h"

int buttoncnt = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    buttoncnt++;
    ui->label->setText("hello");
    ui->progressBar->setValue(buttoncnt);
    QString str = QString::number(buttoncnt);
    ui->lcdNumber->display(str);
}
