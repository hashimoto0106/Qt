#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // 現在の日時を取得
    QDateTime dt = QDateTime::currentDateTime();

    // 以下は time_t tm として対応するものをコメントアウトで記載しています

    // 日付の文字列表示
    // tm.Format("%Y/%m/%d")
    QString strDate = dt.toString("yyyy/MM/dd");
//    qDebug("日付: %s", qPrintable(strDate));

    // 時刻の文字列表示
    // tm.Format("%H/%M/%S")
    QString strTime = dt.toString("hh:mm:ss");
//    qDebug("時刻: %s", qPrintable(strTime));

    QString str = strDate + " " + strTime;
    qDebug("時刻: %s", qPrintable(str));

    ui->textBrowser->append(str);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
}
