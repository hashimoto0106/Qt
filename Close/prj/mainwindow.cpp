#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->~MainWindow, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    int res = QMessageBox::question(this, tr("問い合わせ"), tr("終了しますか？"));
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int res = QMessageBox::question(this, tr("closeEvent"), tr("終了しますか？"));
    if (res == QMessageBox::No) event->ignore();
}
