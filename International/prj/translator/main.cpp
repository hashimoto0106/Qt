#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    const QString trFileName = "translator";
    QString locale = QLocale::system().name();
    QTranslator translator;
    MainWindow w;
    w.show();
    return a.exec();
}
