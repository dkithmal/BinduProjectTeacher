/****************************************************************************
** Meta object code from reading C++ file 'manageclasses.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../manageclasses.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manageclasses.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ManageClasses_t {
    QByteArrayData data[15];
    char stringdata[379];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ManageClasses_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ManageClasses_t qt_meta_stringdata_ManageClasses = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 21),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 26),
QT_MOC_LITERAL(4, 64, 5),
QT_MOC_LITERAL(5, 70, 24),
QT_MOC_LITERAL(6, 95, 38),
QT_MOC_LITERAL(7, 134, 4),
QT_MOC_LITERAL(8, 139, 23),
QT_MOC_LITERAL(9, 163, 45),
QT_MOC_LITERAL(10, 209, 45),
QT_MOC_LITERAL(11, 255, 45),
QT_MOC_LITERAL(12, 301, 24),
QT_MOC_LITERAL(13, 326, 24),
QT_MOC_LITERAL(14, 351, 26)
    },
    "ManageClasses\0on_pBAddGrade_clicked\0"
    "\0on_tWManage_currentChanged\0index\0"
    "on_pBCreateClass_clicked\0"
    "on_cBSelectGrade_3_currentIndexChanged\0"
    "arg1\0on_pBAddStudent_clicked\0"
    "on_cBSelectGradeForRClass_currentIndexChanged\0"
    "on_cBSelectGradeFRStudent_currentIndexChanged\0"
    "on_cBSelectClassFRStudent_currentIndexChanged\0"
    "on_pBRemoveGrade_clicked\0"
    "on_pBRemoveClass_clicked\0"
    "on_pBRemoveStudent_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManageClasses[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08,
       3,    1,   70,    2, 0x08,
       5,    0,   73,    2, 0x08,
       6,    1,   74,    2, 0x08,
       8,    0,   77,    2, 0x08,
       9,    1,   78,    2, 0x08,
      10,    1,   81,    2, 0x08,
      11,    1,   84,    2, 0x08,
      12,    0,   87,    2, 0x08,
      13,    0,   88,    2, 0x08,
      14,    0,   89,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ManageClasses::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ManageClasses *_t = static_cast<ManageClasses *>(_o);
        switch (_id) {
        case 0: _t->on_pBAddGrade_clicked(); break;
        case 1: _t->on_tWManage_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pBCreateClass_clicked(); break;
        case 3: _t->on_cBSelectGrade_3_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_pBAddStudent_clicked(); break;
        case 5: _t->on_cBSelectGradeForRClass_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_cBSelectGradeFRStudent_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_cBSelectClassFRStudent_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_pBRemoveGrade_clicked(); break;
        case 9: _t->on_pBRemoveClass_clicked(); break;
        case 10: _t->on_pBRemoveStudent_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ManageClasses::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ManageClasses.data,
      qt_meta_data_ManageClasses,  qt_static_metacall, 0, 0}
};


const QMetaObject *ManageClasses::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManageClasses::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManageClasses.stringdata))
        return static_cast<void*>(const_cast< ManageClasses*>(this));
    return QDialog::qt_metacast(_clname);
}

int ManageClasses::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
