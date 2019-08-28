#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui->label->setText("hello Qt!!");
}

void MainWindow::on_radioButton_clicked()
{
    if (ui->radioButton->isChecked())
    {
        ui->label->setText("radioButton:On");
    }
    else
    {
        ui->label->setText("radioButton:Off");
    }
}

void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked())
    {
        ui->label->setText("checkBox:On");
    }
    else
    {
        ui->label->setText("checkBox:Off");
    }
}
