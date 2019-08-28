#include <QMainWindow>
#include <QUdpSocket>
#include <QDataStream>
#include <QByteArray>
#include <QDateTime>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void sendDatagram();
    void processPendingDatagram();
    void showMessage();

private:
    Ui::MainWindow *ui;
    QUdpSocket udpsocket1;//送信側
    QUdpSocket udpsocket2;//受信側
    QString message;
};
