#include "mainwindow.h"

#include <QtSingleApplication>

int main(int argc, char *argv[])
{
    QtSingleApplication  a(argc, argv);

    if( a.isRunning() ) // すでに実行中チェック
        return !a.sendMessage("実行中のインスタンスに渡す何らかの文字列"); // messageReceivedで受け取る

    MainWindow w;
    w.show();
    return a.exec();
}
