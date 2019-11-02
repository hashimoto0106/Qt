#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *cw = new QWidget();
    setCentralWidget(cw);

    //ラベル1
    QLabel *label_1 = new QLabel(tr("label-1"), cw);
    label_1->setGeometry(10, 10, 80, 20);

    //ラベル2
    QLabel *label_2 = new QLabel(tr("label-2"), cw);
    label_2->setGeometry(10, 40, 80, 20);

    //ボタン1
    QPushButton *pb1 = new QPushButton(tr("PushButton-1"), cw);
    pb1->setGeometry(80, 10, 100, 20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

