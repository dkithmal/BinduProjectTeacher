/****************************************************************************
** Meta object code from reading C++ file 'newmcqpaper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../newmcqpaper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newmcqpaper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NewMcqPaper_t {
    QByteArrayData data[12];
    char stringdata[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NewMcqPaper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NewMcqPaper_t qt_meta_stringdata_NewMcqPaper = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 36),
QT_MOC_LITERAL(2, 49, 0),
QT_MOC_LITERAL(3, 50, 5),
QT_MOC_LITERAL(4, 56, 19),
QT_MOC_LITERAL(5, 76, 33),
QT_MOC_LITERAL(6, 110, 21),
QT_MOC_LITERAL(7, 132, 17),
QT_MOC_LITERAL(8, 150, 22),
QT_MOC_LITERAL(9, 173, 18),
QT_MOC_LITERAL(10, 192, 19),
QT_MOC_LITERAL(11, 212, 19)
    },
    "NewMcqPaper\0on_cBNoOfChoises_currentIndexChanged\0"
    "\0index\0on_pBAddMcq_clicked\0"
    "on_tWPaperCreation_currentChanged\0"
    "on_pBPrivious_clicked\0on_pBNext_clicked\0"
    "on_pBEPrivious_clicked\0on_pBENext_clicked\0"
    "on_pBCClose_clicked\0on_pBEClose_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewMcqPaper[] = {

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
       1,    1,   59,    2, 0x08,
       4,    0,   62,    2, 0x08,
       5,    1,   63,    2, 0x08,
       6,    0,   66,    2, 0x08,
       7,    0,   67,    2, 0x08,
       8,    0,   68,    2, 0x08,
       9,    0,   69,    2, 0x08,
      10,    0,   70,    2, 0x08,
      11,    0,   71,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NewMcqPaper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NewMcqPaper *_t = static_cast<NewMcqPaper *>(_o);
        switch (_id) {
        case 0: _t->on_cBNoOfChoises_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pBAddMcq_clicked(); break;
        case 2: _t->on_tWPaperCreation_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pBPrivious_clicked(); break;
        case 4: _t->on_pBNext_clicked(); break;
        case 5: _t->on_pBEPrivious_clicked(); break;
        case 6: _t->on_pBENext_clicked(); break;
        case 7: _t->on_pBCClose_clicked(); break;
        case 8: _t->on_pBEClose_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject NewMcqPaper::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewMcqPaper.data,
      qt_meta_data_NewMcqPaper,  qt_static_metacall, 0, 0}
};


const QMetaObject *NewMcqPaper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewMcqPaper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewMcqPaper.stringdata))
        return static_cast<void*>(const_cast< NewMcqPaper*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewMcqPaper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
