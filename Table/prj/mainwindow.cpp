#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget.h>

#define D_MAX_COL 4
#define D_MAX_ROW 7


#define COL_1 0
#define COL_2 1
#define COL_3 2
#define COL_4 3
#define COL_5 4
#define COL_6 5
#define COL_MAX 6

int m_row = 0;
int count = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ラベル１のlineEditに文字を表示する。
    ui->lineEdit->setText("TEST");

    //——————————
    //ボタンイベント登録
    //——————————
//    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(clickPshBtn()));

    //——————————
    //テーブル生成
    //——————————
    QTableWidget* tblWdgt;
    tblWdgt = ui->tableWidget;

    // クリア
    tblWdgt->clear();

    // テーブルの列数、行数を設定する
    tblWdgt->setColumnCount( D_MAX_COL );
    tblWdgt->setRowCount( D_MAX_ROW );

    // 列のタイトル設定
    tblWdgt->setHorizontalHeaderLabels(
     QStringList()
      << tr("Title 1")
      << tr("Title 2" )
      << tr("Title 3" )
      << tr("Title 4" )
      << tr("Title 5") );

    //——————————
    //テーブルプロパティ設定
    //——————————
    //セル選択不可にする場合
    tblWdgt->setSelectionMode(QAbstractItemView::NoSelection);

    //いわゆるExcelみたいなタイプ。Ctrl＋クリックで飛び地の選択も可能。
    tblWdgt->setSelectionMode(QAbstractItemView::ExtendedSelection);

    //ダブルクリックでの編集不可にする
    tblWdgt->setEditTriggers(QAbstractItemView::NoEditTriggers);
//       tblWdgt->setItemDelegateForColumn(0, new QAbstractItemDelegate(tblWdgt));

    //カラム[0]の列幅設定
    tblWdgt->setColumnWidth(COL_1,100);
    tblWdgt->verticalHeader()->setDefaultSectionSize(20);

    // 選択したセルの色をデフォルトのグレーから変更する
    // 親のカラーパレットを取得し変更する
    //Qt::red, Qt::blue, Qt::green, Qt::yellow, Qt::magenta, Qt::cyan
    QPalette palette = tblWdgt->palette();
    palette.setColor(QPalette::Highlight, Qt::red);//現在選択されている項目の背景色
    palette.setColor(QPalette::HighlightedText,Qt::green);//現在選択されている項目の文字色
    tblWdgt->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QTableWidget* tblWdgt = ui->tableWidget;
    //最大行数の場合、先頭行の削除
    if(m_row >= D_MAX_ROW){
        tblWdgt->removeRow(0);
        m_row--;

        //最終行追加
        tblWdgt->insertRow(m_row);
    }

    //データを追加する
    count++;
    QTableWidgetItem *item[COL_MAX];
    item[COL_1] = new QTableWidgetItem(QString("data1 #%8.0f").arg(0.1));
    item[COL_2] = new QTableWidgetItem(QString("data2 #%8.0f").arg(0.1));
    item[COL_3] = new QTableWidgetItem(QString("data3 #%8.0f").arg(0.1));
    item[COL_4] = new QTableWidgetItem(QString("data4 #%8.0f").arg(0.1));
//    item[COL_5] = new QTableWidgetItem(QString("data5 #%8.0f").arg(0.1));

    item[COL_2]->setTextAlignment(Qt::AlignHCenter);
//    item[COL_3]->setTextAlignment(Qt::AlignHCenter);

    for(int ncol=0;ncol<COL_MAX;ncol++){ tblWdgt->setItem(m_row, ncol, item[ncol]);}

    // 指定したアイテム（行）までスクロール(列は未指定）
    QTableWidgetItem *pItem = tblWdgt->item( m_row, 0 );
    tblWdgt->scrollToItem( pItem );

    //行インクリメント
    m_row++;
}

void MainWindow::on_pushButton_2_clicked()
{
    QTableWidget* tblWdgt = ui->tableWidget;
    tblWdgt->setItem(m_row, 0, new QTableWidgetItem("DD/MM/YYYY hh:mm:ss.sss"));
    tblWdgt->setItem(m_row, 1, new QTableWidgetItem("Signal 0001"));
    tblWdgt->setItem(m_row, 2, new QTableWidgetItem("On"));
    m_row++;
}

void MainWindow::on_pushButton_3_clicked()
{
    QTableWidget* tblWdgt = ui->tableWidget;
    tblWdgt->clear();
//    tblWdgt->removeRow(m_row);
    m_row=0;
}
