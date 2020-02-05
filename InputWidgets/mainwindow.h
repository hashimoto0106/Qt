#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_dial_actionTriggered(int action);

    void on_dial_sliderMoved(int position);

    void on_horizontalScrollBar_actionTriggered(int action);

    void on_dial_rangeChanged(int min, int max);

    void on_horizontalScrollBar_rangeChanged(int min, int max);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_doubleSpinBox_2_valueChanged(const QString &arg1);

    void on_textEdit_textChanged();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
