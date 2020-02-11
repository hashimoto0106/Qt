#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setToolTip("Hello, world");
    ui->radioButton->setToolTip("radioButton ToopTip");
}

MainWindow::~MainWindow()
{
    delete ui;
}

