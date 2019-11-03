#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
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

void MainWindow::testVBoxLayout()
{
    QDialog aDlg;
    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(new QLabel(tr("label-1")));
    layout->addWidget(new QLineEdit());
    layout->addWidget(new QLabel(tr("label-2")));
    layout->addStretch();
    layout->addWidget(new QPushButton(tr("QPushButton-1")));

    aDlg.setLayout(layout);
    aDlg.exec();
}


void MainWindow::testHierarchiBL()
{
    QDialog aDlg;
    QVBoxLayout *vLayout = new QVBoxLayout();

    QHBoxLayout *hLayout1 = new QHBoxLayout();
    hLayout1->addWidget(new QLabel(tr("hoge")));
    hLayout1->addWidget(new QLineEdit());
    vLayout->addLayout(hLayout1);

    QHBoxLayout *hLayout2 = new QHBoxLayout();
    hLayout2->addWidget(new QLabel(tr("hogeHoge")));
    hLayout2->addWidget(new QLineEdit());
    vLayout->addLayout(hLayout2);

    QHBoxLayout *hLayout3 = new QHBoxLayout();
    hLayout3->addStretch();
    hLayout3->addWidget(new QPushButton(tr("QPushButton-1")));
    hLayout3->addStretch();
    vLayout->addLayout(hLayout3);

    aDlg.setLayout(vLayout);
    aDlg.exec();
}
