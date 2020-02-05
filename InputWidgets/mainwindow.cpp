#include "mainwindow.h"
#include "ui_mainwindow.h"

int comboBoxCount = 0;

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

void MainWindow::on_dial_actionTriggered(int action)
{
    QString str = QString::number(action);
    ui->label->setText(str);
}


void MainWindow::on_dial_sliderMoved(int position)
{
    QString str = QString::number(position);
    ui->label->setText(str);
}


void MainWindow::on_horizontalScrollBar_actionTriggered(int action)
{
    QString str = QString::number(action);
    ui->label->setText(str);
}

void MainWindow::on_dial_rangeChanged(int min, int max)
{

}

void MainWindow::on_horizontalScrollBar_rangeChanged(int min, int max)
{
    QString str = QString::number(min);
    ui->label->setText(str);
}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    ui->label->setText(arg1);
}

void MainWindow::on_doubleSpinBox_2_valueChanged(const QString &arg1)
{
    ui->label->setText(arg1);
}

void MainWindow::on_textEdit_textChanged()
{

}

void MainWindow::on_pushButton_clicked()
{
    comboBoxCount++;
    QString str = QString::number(comboBoxCount);
    ui->comboBox->addItem(str);
//    str = ui->comboBox->currentIndex().toString();
    ui->label->setText(str);

}
