/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[19];
    char stringdata0[458];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 11), // "receiveData"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 26), // "on_pushButton_open_clicked"
QT_MOC_LITERAL(4, 47, 27), // "on_pushButton_setID_clicked"
QT_MOC_LITERAL(5, 75, 30), // "on_pushButton_verifyID_clicked"
QT_MOC_LITERAL(6, 106, 29), // "on_pushButton_openAir_clicked"
QT_MOC_LITERAL(7, 136, 30), // "on_pushButton_closeAir_clicked"
QT_MOC_LITERAL(8, 167, 30), // "on_pushButton_airIndex_clicked"
QT_MOC_LITERAL(9, 198, 32), // "on_pushButton_indexQuery_clicked"
QT_MOC_LITERAL(10, 231, 36), // "on_pushButton_indexStopQuery_..."
QT_MOC_LITERAL(11, 268, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(12, 290, 10), // "on_timeout"
QT_MOC_LITERAL(13, 301, 21), // "on_temperaturetimeout"
QT_MOC_LITERAL(14, 323, 15), // "on_querytimeout"
QT_MOC_LITERAL(15, 339, 29), // "on_pushButton_setTemp_clicked"
QT_MOC_LITERAL(16, 369, 29), // "on_pushButton_tempCmd_clicked"
QT_MOC_LITERAL(17, 399, 30), // "on_pushButton_relayCmd_clicked"
QT_MOC_LITERAL(18, 430, 27) // "on_pushButton_query_clicked"

    },
    "Widget\0receiveData\0\0on_pushButton_open_clicked\0"
    "on_pushButton_setID_clicked\0"
    "on_pushButton_verifyID_clicked\0"
    "on_pushButton_openAir_clicked\0"
    "on_pushButton_closeAir_clicked\0"
    "on_pushButton_airIndex_clicked\0"
    "on_pushButton_indexQuery_clicked\0"
    "on_pushButton_indexStopQuery_clicked\0"
    "on_pushButton_clicked\0on_timeout\0"
    "on_temperaturetimeout\0on_querytimeout\0"
    "on_pushButton_setTemp_clicked\0"
    "on_pushButton_tempCmd_clicked\0"
    "on_pushButton_relayCmd_clicked\0"
    "on_pushButton_query_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveData(); break;
        case 1: _t->on_pushButton_open_clicked(); break;
        case 2: _t->on_pushButton_setID_clicked(); break;
        case 3: _t->on_pushButton_verifyID_clicked(); break;
        case 4: _t->on_pushButton_openAir_clicked(); break;
        case 5: _t->on_pushButton_closeAir_clicked(); break;
        case 6: _t->on_pushButton_airIndex_clicked(); break;
        case 7: _t->on_pushButton_indexQuery_clicked(); break;
        case 8: _t->on_pushButton_indexStopQuery_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_timeout(); break;
        case 11: _t->on_temperaturetimeout(); break;
        case 12: _t->on_querytimeout(); break;
        case 13: _t->on_pushButton_setTemp_clicked(); break;
        case 14: _t->on_pushButton_tempCmd_clicked(); break;
        case 15: _t->on_pushButton_relayCmd_clicked(); break;
        case 16: _t->on_pushButton_query_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
