#include "MultiSignal.h"
#include <QWidget>
#include <QSignalMapper>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QFileDialog>



MultiSignal::MultiSignal(QWidget *parent) : QWidget(parent)
{
    m_sigmap=new QSignalMapper(this);
    QFormLayout *playout=new QFormLayout;
    int ni;
    QString stitle(tr("test-input-%1"));
    QString sbutton(tr("%1"));
    for(ni=0;ni<3;ni++){
        //	create parts
        m_title[ni]=new QLabel(stitle.arg(ni+1),this);
        m_filename[ni]=new QLineEdit(this);
        m_button[ni]=new QPushButton(sbutton.arg(ni+1),this);

        //	set of layout
        QHBoxLayout *hboxLayout = new QHBoxLayout;
        hboxLayout->addWidget(m_filename[ni]);
        hboxLayout->addWidget(m_button[ni]);
        playout->addRow(m_title[ni],hboxLayout);

        //	signal map
        connect(m_button[ni], SIGNAL(clicked()), m_sigmap, SLOT(map()));
        m_sigmap->setMapping(m_button[ni], m_filename[ni]);
    }
    setLayout(playout);
    /*
    +--------------------------------------------+
    |+------------------------------------------+|
    ||            +---------------+------------+||
    || m_title[0] | m_filename[0] |m_button[0] |||
    ||            +---------------+------------+||
    ||            +---------------+------------+||
    || m_title[1] | m_filename[1] |m_button[1] |||
    ||            +---------------+------------+||
    ||            +---------------+------------+||
    || m_title[2] | m_filename[1] |m_button[2] |||
    ||            +---------------+------------+||
    |+------------------------------------------+|
    +--------------------------------------------+
    */

    //	connect
    connect(m_sigmap, SIGNAL(mapped(QWidget *)),this, SLOT(OnClickButton(QWidget *)));
}
void MultiSignal::OnClickButton(QWidget *wlineedit)
{
    QString sfileName = QFileDialog::getOpenFileName (
                this,
                tr("Choose a filename"),
                "",
                tr("All files (*.*)"),
                0,
                0
            );

    if(!sfileName.isEmpty()){
        QLineEdit *pline = qobject_cast<QLineEdit *>(wlineedit);
        if(pline){
            pline->setText(sfileName);
        }
    }
}
