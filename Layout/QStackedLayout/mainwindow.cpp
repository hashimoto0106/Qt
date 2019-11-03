#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QStackedLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QCalendarWidget>
#include <QPlainTextEdit>

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


void MainWindow::testStackedLayout()
{
    QDialog aDlg;
    QVBoxLayout *vLayout = new QVBoxLayout();
    QComboBox *pageComboBox = new QComboBox();

    //ページ切り替え
    pageComboBox->addItem(tr("Page 1"));
    pageComboBox->addItem(tr("Page 2"));
    pageComboBox->addItem(tr("Page 3"));
    vLayout->addWidget(pageComboBox);

    QStackedLayout *stackedLayout = new QStackedLayout();
    stackedLayout->addWidget(new QCalendarWidget);
    stackedLayout->addWidget(new QDialog);
    stackedLayout->addWidget(new QPlainTextEdit);

    vLayout->addLayout(stackedLayout);

    connect(pageComboBox, SIGNAL(activated(int)), stackedLayout, SLOT(setCurrentIndex(int)));

    aDlg.setLayout(vLayout);
    aDlg.exec();
}
