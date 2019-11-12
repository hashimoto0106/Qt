#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

void test1(void)
{
    QDialog aDlg;
    QVBoxLayout *vLayout = new QVBoxLayout();

    QScrollArea * scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ///常に垂直なスクロールバーを表示

    scrollArea->setWidget(new QLabel("Small Text1"));
    scrollArea->setWidget(new QLabel("Small Text2"));
    scrollArea->setWidget(new QLabel("Small Text3"));

    vLayout->addWidget(scrollArea);
    vLayout->addStretch();

    aDlg.setLayout(vLayout);
    aDlg.exec();
}

void test2(void)
{
    QDialog aDlg;
    QGridLayout *gLayout = new QGridLayout();

    gLayout->addWidget(new QLabel(("hoge")), 0, 0, Qt::AlignRight);
    gLayout->addWidget(new QLineEdit(), 0, 1, Qt::AlignRight);
    gLayout->addWidget(new QLabel(("hogeHoge")), 1, 0, Qt::AlignRight);
    gLayout->addWidget(new QLineEdit(), 1, 1, Qt::AlignRight);

    aDlg.setLayout(gLayout);
    aDlg.exec();
}

void test3(void)
{
    QDialog aDlg;
    QGridLayout *gLayout = new QGridLayout();

    gLayout->addWidget(new QLabel(("hoge")), 0, 0, Qt::AlignRight);
    gLayout->addWidget(new QLineEdit(), 0, 1, Qt::AlignRight);
    gLayout->addWidget(new QLabel(("hogeHoge")), 1, 0, Qt::AlignRight);
    gLayout->addWidget(new QLineEdit(), 1, 1, Qt::AlignRight);

    QScrollArea * scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    scrollArea->setWidget(gLayout);

//    aDlg.setLayout(scrollArea);
    aDlg.exec();
}

void test4(void)
{
    QDialog aDlg;
    QVBoxLayout *vLayout = new QVBoxLayout();

    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setWidgetResizable(1);

    QGridLayout *gLayout = new QGridLayout();
    gLayout->addWidget(new QLabel("hoge"));
    gLayout->addWidget(new QLabel("hoge"));
    gLayout->addWidget(new QLabel("hoge"));
    gLayout->addWidget(new QLabel("hoge"));
    gLayout->addWidget(new QLabel("hoge"));
    gLayout->addWidget(new QLabel("hoge"));
    gLayout->addWidget(new QLabel("hoge"));
    gLayout->addWidget(new QLabel("hoge"));
    gLayout->addWidget(new QLabel("hoge"));
    gLayout->addWidget(new QLabel("hoge"));

    scrollArea->setLayout(gLayout);
//    scrollArea->setWidget(new QLabel("Small Text1"));
//    scrollArea->resize(200, 200);
    scrollArea->setMaximumHeight(220);

    vLayout->addWidget(scrollArea);
    aDlg.setLayout(vLayout);
    aDlg.exec();
}

void test5(void)
{
    QDialog aDlg;
    auto * layout = new QVBoxLayout();
    auto * scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable( true );
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    layout->addWidget( scrollArea );
    auto * container = new QWidget();
    scrollArea->setWidget( container );
    layout = new QVBoxLayout(container);
    auto * button1 = new QPushButton( "1", container);
    auto * button2 = new QPushButton( "2", container);
    auto * button3 = new QPushButton( "3", container);
    layout->addWidget( button1 );
    layout->addWidget( button2 );
    layout->addWidget( button3 );
    aDlg.setLayout(layout);
    aDlg.exec();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    test1();
//    test2();
//    test3();
      test4();
//      test5();
}


MainWindow::~MainWindow()
{
    delete ui;
}

