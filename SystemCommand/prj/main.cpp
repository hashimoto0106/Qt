#include "mainwindow.h"

#include <QApplication>
#include <QProcess>
#include <QDir>


void testSystemCommand(void)
{
    QProcess process;
//    process.setWorkingDirectory("D:\\MyWork\\Temp\\source");
    process.start("git", QStringList() << "gui");
    process.waitForFinished();
    process.close();

    //1Line実行
//    bool res = QProcess::startDetached("git gui", QStringList(), "D:\\MyWork\\Temp\\source");
//    if (!res) {
//     //show error message
//    }

//    QDir::setCurrent("D:/MyWork/Temp/source");
//    system("git gui");
}


void testWinSCP(void)
{
//    QProcess process;
//    process.setWorkingDirectory("C:\\Program Files (x86)\\WinSCP");
//    process.start("WinSCP.exe");

    QDir::setCurrent("C:\\Program Files (x86)\\WinSCP");
    system("WinSCP.exe");
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    testSystemCommand();
//    testWinSCP();   //WinSCP


    return a.exec();
}
