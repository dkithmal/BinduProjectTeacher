/****************************************************************************
** Meta object code from reading C++ file 'servercliant.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../servercliant.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servercliant.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ServerCliant_t {
    QByteArrayData data[10];
    char stringdata[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ServerCliant_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ServerCliant_t qt_meta_stringdata_ServerCliant = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 8),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 11),
QT_MOC_LITERAL(4, 35, 11),
QT_MOC_LITERAL(5, 47, 9),
QT_MOC_LITERAL(6, 57, 12),
QT_MOC_LITERAL(7, 70, 9),
QT_MOC_LITERAL(8, 80, 12),
QT_MOC_LITERAL(9, 93, 5)
    },
    "ServerCliant\0FileSent\0\0studentName\0"
    "FileRecived\0connected\0disconnected\0"
    "readyRead\0bytesWritten\0bytes\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerCliant[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x05,
       4,    1,   47,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    0,   50,    2, 0x0a,
       6,    0,   51,    2, 0x0a,
       7,    0,   52,    2, 0x0a,
       8,    1,   53,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    9,

       0        // eod
};

void ServerCliant::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerCliant *_t = static_cast<ServerCliant *>(_o);
        switch (_id) {
        case 0: _t->FileSent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->FileRecived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->connected(); break;
        case 3: _t->disconnected(); break;
        case 4: _t->readyRead(); break;
        case 5: _t->bytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ServerCliant::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerCliant::FileSent)) {
                *result = 0;
            }
        }
        {
            typedef void (ServerCliant::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerCliant::FileRecived)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ServerCliant::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ServerCliant.data,
      qt_meta_data_ServerCliant,  qt_static_metacall, 0, 0}
};


const QMetaObject *ServerCliant::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerCliant::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerCliant.stringdata))
        return static_cast<void*>(const_cast< ServerCliant*>(this));
    return QObject::qt_metacast(_clname);
}

int ServerCliant::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ServerCliant::FileSent(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServerCliant::FileRecived(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
