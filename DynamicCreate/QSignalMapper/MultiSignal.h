#ifndef MULTISIGNAL_H
#define MULTISIGNAL_H

#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class MultiSignal : public QWidget
{
    Q_OBJECT

public:
    MultiSignal(QWidget *parent);


public slots:
    void OnClickButton(QWidget *);
signals:

private:
    QLabel *m_title[3];
    QLineEdit *m_filename[3];
    QPushButton *m_button[3];

    QSignalMapper *m_sigmap;
};

#endif // MULTISIGNAL_H
