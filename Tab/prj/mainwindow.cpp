#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDialog aDlg;
    QVBoxLayout *vLayout = new QVBoxLayout();
    QGridLayout *gLayout = new QGridLayout();

    QTabWidget *tabWidget = new QTabWidget();
    QTextEdit *editor1 = new QTextEdit(tr("1つめのタブ"), tabWidget);
    QTextEdit *editor2 = new QTextEdit(tr("2つめのタブ"), tabWidget);
    tabWidget->addTab(editor1, tr("TAB1"));
    tabWidget->addTab(editor2, tr("TAB2"));

    gLayout->addWidget(tabWidget, 0, 0, Qt::AlignRight);
//    gLayout->addWidget(new QLabel(tr("hoge")), 0, 0, Qt::AlignRight);

    vLayout->addLayout(gLayout);
    vLayout->addStretch();

    aDlg.setLayout(vLayout);
    aDlg.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

