#include "mainwindow.h"

#include <QApplication>
#include <QTabWidget>
#include <QTextEdit>

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

////    QDialog aDlg;
//    QVBoxLayout *vLayout = new QVBoxLayout();
//    QGridLayout *gLayout = new QGridLayout();

//    QTabWidget *tabWidget = new QTabWidget();
//    QTextEdit *editor1 = new QTextEdit(("1つめのタブ"), tabWidget);
//    QTextEdit *editor2 = new QTextEdit(("2つめのタブ"), tabWidget);
//    tabWidget->addTab(editor1, ("TAB1"));
//    tabWidget->addTab(editor2, ("TAB2"));

//    gLayout->addWidget(tabWidget, 0, 0, Qt::AlignRight);
//    gLayout->addWidget(new QLabel(("hoge")), 0, 0, Qt::AlignRight);

//    vLayout->addLayout(gLayout);
//    vLayout->addStretch();

//    w.setLayout(vLayout);
////    aDlg.setLayout(vLayout);
////    aDlg.exec();

    w.show();
    return a.exec();
}
