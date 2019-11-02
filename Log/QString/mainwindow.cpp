#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //文字初期化
    QString text0;
    ui->label->setText(text0);

    QString text1("abc");
    ui->label_2->setText(text1);

    QString text2 = "xyz";
    ui->label_3->setText(text2);

    //文字コード指定
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
////    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Shift-JIS"));
//    QString text3 = "あいうえお";
//    ui->label_4->setText(text3);

    //arg()

}

MainWindow::~MainWindow()
{
    delete ui;
}

