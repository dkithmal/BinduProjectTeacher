/****************************************************************************
** Meta object code from reading C++ file 'selectstuforadddetails.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../selectstuforadddetails.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectstuforadddetails.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SelectStuForAddDetails_t {
    QByteArrayData data[5];
    char stringdata[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SelectStuForAddDetails_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SelectStuForAddDetails_t qt_meta_stringdata_SelectStuForAddDetails = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 24),
QT_MOC_LITERAL(2, 48, 0),
QT_MOC_LITERAL(3, 49, 5),
QT_MOC_LITERAL(4, 55, 23)
    },
    "SelectStuForAddDetails\0on_tWSelectClass_clicked\0"
    "\0index\0on_pBAddDetails_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectStuForAddDetails[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08,
       4,    0,   27,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,

       0        // eod
};

void SelectStuForAddDetails::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectStuForAddDetails *_t = static_cast<SelectStuForAddDetails *>(_o);
        switch (_id) {
        case 0: _t->on_tWSelectClass_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_pBAddDetails_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SelectStuForAddDetails::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SelectStuForAddDetails.data,
      qt_meta_data_SelectStuForAddDetails,  qt_static_metacall, 0, 0}
};


const QMetaObject *SelectStuForAddDetails::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectStuForAddDetails::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SelectStuForAddDetails.stringdata))
        return static_cast<void*>(const_cast< SelectStuForAddDetails*>(this));
    return QDialog::qt_metacast(_clname);
}

int SelectStuForAddDetails::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
