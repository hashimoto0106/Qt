#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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


void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox;
        msgBox.setText("Hello World!! This is MessageBox!!");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);

        int ret = msgBox.exec();//結果がretに格納される

        QMessageBox msgBox2;

        switch (ret) {
        case QMessageBox::Save://save押されたら
            msgBox2.setText( "Save was clicked" );
            msgBox2.exec();
            break;
        case QMessageBox::Discard://discard押されたら
            msgBox2.setText( "Don't Save was clicked" );
            msgBox2.exec();
            break;
        case QMessageBox::Cancel://キャンセル押されたら
            msgBox2.setText( "Cancel was clicked" );
            msgBox2.exec();
            break;
        default:
            // 来ないけど一応。
            break;
        }
    int res = msgBox.exec();
}
