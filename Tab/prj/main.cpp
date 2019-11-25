#include "mainwindow.h"

#include <QApplication>
#include <QTabWidget>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QTabWidget tabWidget;
    QTextEdit *editor1 = new QTextEdit(("1つめのタブ"), &tabWidget);
    QTextEdit *editor2 = new QTextEdit(("2つめのタブ"), &tabWidget);
    tabWidget.addTab(editor1, ("TAB1"));
    tabWidget.addTab(editor2, ("TAB2"));
//    tabWidget.setTabClosable(true);

    w.show();
    return a.exec();
}
