#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
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


void MainWindow::testFormLayout()
{
    QDialog aDlg;
    QVBoxLayout *vLayout = new QVBoxLayout();
    QFormLayout *fLayout = new QFormLayout();

    fLayout->setLabelAlignment(Qt::AlignRight);

    fLayout->addRow(tr("hoge"), new QLineEdit());
    fLayout->addRow(tr("hogeHoge"), new QLineEdit());

    vLayout->addLayout(fLayout);
    vLayout->addStretch();

    aDlg.setLayout(vLayout);
    aDlg.exec();
}
