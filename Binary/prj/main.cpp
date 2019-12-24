#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QByteArray data
        = QString("48656c6c6f").toUtf8().toHex();
    qDebug() << data;
        /// 書き込むバイナリデータ
    QFile file("output.bin");
    file.open(QFile::ReadWrite);
//    file.open(QIODevice::ReadWrite);
    QDataStream ds(&file);
    ds.setVersion(QDataStream::Qt_5_1);
    ds >> data;
    file.close();

    // ***********************************************
    file.open(QFile::ReadWrite);
    file.write(data);
    file.close();

    // ***********************************************
    QFile file1("output1.bin");
    if (!file1.open(QIODevice::WriteOnly)) //オープン成功か失敗か
    {
        return -1;
    }
    QDataStream out(&file1);//バイナリ読み書きに使う
    out.setVersion(QDataStream::Qt_5_1);//version番号。定数を入れても良い。
    out << quint32(0x12345678);
    qDebug() << quint32(0x12345678);
    file1.close();

    w.show();
    return a.exec();
}
