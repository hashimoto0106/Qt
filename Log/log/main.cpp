#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qDebug() << "test";
    qDebug() << "int:" << 10;
    qDebug() << "double:" << 123.45;
    qDebug() << "string:" << u8"abcあいう";
QString debugMsg = "Error in " + __FILE__ + ":" + __FUNCTION__ + "(" + __LINE__ + ")" + " at " + __DATE__;
//QString debugMsg = tr("Error in ") + __FILE__ + tr(":") + __FUNCTION__ + tr("(") + __LINE__ + tr(")") + tr(" at ") + __DATE__;
    return a.exec();
}
