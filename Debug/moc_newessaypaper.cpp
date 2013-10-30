/****************************************************************************
** Meta object code from reading C++ file 'newessaypaper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../newessaypaper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newessaypaper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewEssayPaper_t {
    QByteArrayData data[9];
    char stringdata[168];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NewEssayPaper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NewEssayPaper_t qt_meta_stringdata_NewEssayPaper = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 29),
QT_MOC_LITERAL(2, 44, 0),
QT_MOC_LITERAL(3, 45, 33),
QT_MOC_LITERAL(4, 79, 5),
QT_MOC_LITERAL(5, 85, 21),
QT_MOC_LITERAL(6, 107, 17),
QT_MOC_LITERAL(7, 125, 22),
QT_MOC_LITERAL(8, 148, 18)
    },
    "NewEssayPaper\0on_pBAddEssayQuestion_clicked\0"
    "\0on_tWPaperCreation_currentChanged\0"
    "index\0on_pBPrivious_clicked\0"
    "on_pBNext_clicked\0on_pBEPrivious_clicked\0"
    "on_pBENext_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewEssayPaper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08,
       3,    1,   45,    2, 0x08,
       5,    0,   48,    2, 0x08,
       6,    0,   49,    2, 0x08,
       7,    0,   50,    2, 0x08,
       8,    0,   51,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewEssayPaper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewEssayPaper *_t = static_cast<NewEssayPaper *>(_o);
        switch (_id) {
        case 0: _t->on_pBAddEssayQuestion_clicked(); break;
        case 1: _t->on_tWPaperCreation_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pBPrivious_clicked(); break;
        case 3: _t->on_pBNext_clicked(); break;
        case 4: _t->on_pBEPrivious_clicked(); break;
        case 5: _t->on_pBENext_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject NewEssayPaper::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NewEssayPaper.data,
      qt_meta_data_NewEssayPaper,  qt_static_metacall, 0, 0}
};


const QMetaObject *NewEssayPaper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewEssayPaper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewEssayPaper.stringdata))
        return static_cast<void*>(const_cast< NewEssayPaper*>(this));
    return QWidget::qt_metacast(_clname);
}

int NewEssayPaper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
