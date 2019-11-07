#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDialog aDlg;
    QVBoxLayout *vLayout = new QVBoxLayout();
    QGridLayout *gLayout = new QGridLayout();

    gLayout->addWidget(new QLabel(tr("hoge")), 0, 0, Qt::AlignRight);
    gLayout->addWidget(new QLineEdit(), 0, 1, Qt::AlignRight);
    gLayout->addWidget(new QLabel(tr("hogeHoge")), 1, 0, Qt::AlignRight);
    gLayout->addWidget(new QLineEdit(), 1, 1, Qt::AlignRight);

    QScrollArea * scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ///常に垂直なスクロールバーを表示

    scrollArea->setWidget(new QLabel("Small Text1"));

    vLayout->addWidget(scrollArea);
    vLayout->addStretch();

    aDlg.setLayout(vLayout);
    aDlg.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

