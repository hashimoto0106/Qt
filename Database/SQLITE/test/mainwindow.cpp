#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

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

    //変数textにTextEditの内容を取得して代入する。
    QString text= ui->textEdit->toPlainText();

    // データベースを開く。無ければ作る。
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sampledatabase.db");
    db.open();
    qDebug() << "Database作成";

    // 無い場合テーブルを作る。
    QSqlQuery query(db);
    query.exec("create table sample(id INTEGER PRIMARY KEY AUTOINCREMENT, memo text)");
    qDebug() << "テーブル作成";

    // データを書き込む
    query.prepare("insert into sample (memo) values (?)");
    query.bindValue(0, text);
    query.exec();

    // データを出力する
    qDebug() << "内容";
    //追加したmemoの内容と一致するものだけをWhereで取り出す。
    query.exec("select * from sample WHERE memo = '"+text+"'");
    //最後まで繰り返す
    while (query.next()) {
        int id = query.value(0).toInt();
        QString memo = query.value(1).toString();
        qDebug() << QString("id(%1),memo(%2)").arg(id).arg(memo);
    }

    db.close();
}
