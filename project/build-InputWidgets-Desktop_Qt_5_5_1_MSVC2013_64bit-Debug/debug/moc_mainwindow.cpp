/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../InputWidgets/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_dial_actionTriggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "action"
QT_MOC_LITERAL(4, 43, 19), // "on_dial_sliderMoved"
QT_MOC_LITERAL(5, 63, 8), // "position"
QT_MOC_LITERAL(6, 72, 38), // "on_horizontalScrollBar_action..."
QT_MOC_LITERAL(7, 111, 20), // "on_dial_rangeChanged"
QT_MOC_LITERAL(8, 132, 3), // "min"
QT_MOC_LITERAL(9, 136, 3), // "max"
QT_MOC_LITERAL(10, 140, 35), // "on_horizontalScrollBar_rangeC..."
QT_MOC_LITERAL(11, 176, 23), // "on_spinBox_valueChanged"
QT_MOC_LITERAL(12, 200, 4), // "arg1"
QT_MOC_LITERAL(13, 205, 31), // "on_doubleSpinBox_2_valueChanged"
QT_MOC_LITERAL(14, 237, 23), // "on_textEdit_textChanged"
QT_MOC_LITERAL(15, 261, 21) // "on_pushButton_clicked"

    },
    "MainWindow\0on_dial_actionTriggered\0\0"
    "action\0on_dial_sliderMoved\0position\0"
    "on_horizontalScrollBar_actionTriggered\0"
    "on_dial_rangeChanged\0min\0max\0"
    "on_horizontalScrollBar_rangeChanged\0"
    "on_spinBox_valueChanged\0arg1\0"
    "on_doubleSpinBox_2_valueChanged\0"
    "on_textEdit_textChanged\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       6,    1,   65,    2, 0x08 /* Private */,
       7,    2,   68,    2, 0x08 /* Private */,
      10,    2,   73,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      13,    1,   81,    2, 0x08 /* Private */,
      14,    0,   84,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_dial_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_dial_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_horizontalScrollBar_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_dial_rangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_horizontalScrollBar_rangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_spinBox_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_doubleSpinBox_2_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_textEdit_textChanged(); break;
        case 8: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
