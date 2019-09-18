#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    const QString trFileName = "translator_ja";
    QString locale = QLocale::system().name();
    QTranslator translator;
    bool rc = translator.load(trFileName);
    if(!rc){
        qDebug() << "can't open " << trFileName;
    }
    app.installTranslator(&translator);

    MainWindow w;
    w.show();
    return app.exec();
}
