#include "mainwindow.h"

#include <QApplication>
#include <QDateTime>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // 現在の日時を取得
    QDateTime dt = QDateTime::currentDateTime();

    // QStringの割当用一時変数
    QString str;

    // 以下は time_t tm として対応するものをコメントアウトで記載しています

    // 日付の文字列表示
    // tm.Format("%Y/%m/%d")
    str = dt.toString("yyyy/MM/dd");
    qDebug("日付: %s", qPrintable(str));

    // 時刻の文字列表示
    // tm.Format("%H/%M/%S")
    str = dt.toString("hh:mm:ss");
    qDebug("時刻: %s", qPrintable(str));

    return a.exec();
}
