#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QSignalMapper>
#include <QCheckBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout * layout = new QVBoxLayout;

    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(findCheckIndex(int)));

    int checkCount = 5;
    for(int i = 0; i < checkCount; ++i){
        QCheckBox * check = new QCheckBox(QString::number(i + 1));
        check->setObjectName(QString::number(i));
        signalMapper->setMapping(check, i);
            ///i番目のチェックボックスをマッピング
        connect(check, SIGNAL(clicked()), signalMapper, SLOT(map()));
        layout->addWidget(check);
    }

    setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

