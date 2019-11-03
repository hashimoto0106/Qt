#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

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


void MainWindow::testGridLayout()
{
    QDialog aDlg;
    QVBoxLayout *vLayout = new QVBoxLayout();
    QGridLayout *gLayout = new QGridLayout();

    gLayout->addWidget(new QLabel(tr("hoge")), 0, 0, Qt::AlignRight);
    gLayout->addWidget(new QLineEdit(), 0, 1, Qt::AlignRight);
    gLayout->addWidget(new QLabel(tr("hogeHoge")), 1, 0, Qt::AlignRight);
    gLayout->addWidget(new QLineEdit(), 1, 1, Qt::AlignRight);

    vLayout->addLayout(gLayout);
    vLayout->addStretch();

    aDlg.setLayout(vLayout);
    aDlg.exec();
}
