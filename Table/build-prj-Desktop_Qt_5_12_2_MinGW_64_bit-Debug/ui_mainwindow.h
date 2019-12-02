/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(608, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(490, 60, 101, 192));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem14);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 30, 451, 371));
        tableWidget->setRowCount(3);
        tableWidget->setColumnCount(5);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 470, 113, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 470, 75, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 470, 75, 23));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 470, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 608, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = tableWidget->item(0, 0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "1,1", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->item(0, 1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "1,2", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->item(0, 2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "1,3", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "1,4", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(0, 4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "1,5", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(1, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "2,1", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(1, 1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "2,2", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(1, 2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "2,3", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(1, 3);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "2,4", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(1, 4);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "2,5", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(2, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "3,1", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(2, 1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "3,2", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(2, 2);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "3,3", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(2, 3);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "3,4", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(2, 4);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "3,5", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
