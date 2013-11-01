/****************************************************************************
** Meta object code from reading C++ file 'uploadfile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../uploadfile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uploadfile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UploadFile_t {
    QByteArrayData data[8];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UploadFile_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UploadFile_t qt_meta_stringdata_UploadFile = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 27),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 28),
QT_MOC_LITERAL(4, 69, 23),
QT_MOC_LITERAL(5, 93, 19),
QT_MOC_LITERAL(6, 113, 24),
QT_MOC_LITERAL(7, 138, 5)
    },
    "UploadFile\0on_rBSelectHomeWork_clicked\0"
    "\0on_rBSelectOtherFile_clicked\0"
    "on_pushButton_3_clicked\0on_pBUpload_clicked\0"
    "on_tWSelectClass_clicked\0index\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UploadFile[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08,
       3,    0,   40,    2, 0x08,
       4,    0,   41,    2, 0x08,
       5,    0,   42,    2, 0x08,
       6,    1,   43,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,

       0        // eod
};

void UploadFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UploadFile *_t = static_cast<UploadFile *>(_o);
        switch (_id) {
        case 0: _t->on_rBSelectHomeWork_clicked(); break;
        case 1: _t->on_rBSelectOtherFile_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pBUpload_clicked(); break;
        case 4: _t->on_tWSelectClass_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject UploadFile::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UploadFile.data,
      qt_meta_data_UploadFile,  qt_static_metacall, 0, 0}
};


const QMetaObject *UploadFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UploadFile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UploadFile.stringdata))
        return static_cast<void*>(const_cast< UploadFile*>(this));
    return QWidget::qt_metacast(_clname);
}

int UploadFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
