#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QStandardPaths>

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

//http://dorafop.my.coocan.jp/Qt/Qt108.html
void MainWindow::on_pushButton_clicked()
{
    qDebug() << "on_pushButton_clicked";
    // ファイルダイアログ表示時に、デスクトップフォルダを表示する
    QFileDialog::getOpenFileName(this, tr("ファイル選択画面"), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));

    // ファイル選択ダイアログを起動、指定されたファイル名を取得
//    strFileName = QFileDialog::getOpenFileName(this, tr("ファイル選択画面"), QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));

    QFileDialog fileDialog(this);
    fileDialog.setFileMode(QFileDialog::Directory);
    fileDialog.setOption(QFileDialog::ShowDirsOnly, true);
    if(fileDialog.exec()){
        QStringList filePaths = fileDialog.selectedFiles();
    }
}
