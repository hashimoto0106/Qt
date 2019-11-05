#include "mainwindow.h"
#include "MultiSignal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MultiSignal multisignal();
    w.show();
    return a.exec();
}
