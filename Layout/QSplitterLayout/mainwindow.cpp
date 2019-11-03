#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSplitter>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTreeWidget>
#include <QListWidget>
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


void MainWindow::testSplitter()
{
    QDialog aDlg;
    QSplitter *hSplitter = new QSplitter(Qt::Horizontal);
    hSplitter->addWidget(m_tree = new QTreeWidget);
    QSplitter *vSplitter = new QSplitter(Qt::Vertical);
    hSplitter->addWidget(vSplitter);
    vSplitter->addWidget(m_list = new QListWidget);
    vSplitter->addWidget(m_editor = new QPlainTextEdit);
    setCentralWidget(hSplitter)
    aDlg.setLayout(vSplitter);
    aDlg.exec();
}
