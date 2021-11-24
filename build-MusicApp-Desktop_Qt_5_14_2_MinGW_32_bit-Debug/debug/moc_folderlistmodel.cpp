/****************************************************************************
** Meta object code from reading C++ file 'folderlistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MusicApp/folderlistmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'folderlistmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FolderListModel_t {
    QByteArrayData data[13];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FolderListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FolderListModel_t qt_meta_stringdata_FolderListModel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FolderListModel"
QT_MOC_LITERAL(1, 16, 7), // "addFile"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "AudioFile*"
QT_MOC_LITERAL(4, 36, 4), // "file"
QT_MOC_LITERAL(5, 41, 3), // "url"
QT_MOC_LITERAL(6, 45, 4), // "name"
QT_MOC_LITERAL(7, 50, 10), // "removeFile"
QT_MOC_LITERAL(8, 61, 5), // "index"
QT_MOC_LITERAL(9, 67, 14), // "removeLastFile"
QT_MOC_LITERAL(10, 82, 5), // "count"
QT_MOC_LITERAL(11, 88, 6), // "getUrl"
QT_MOC_LITERAL(12, 95, 7) // "getName"

    },
    "FolderListModel\0addFile\0\0AudioFile*\0"
    "file\0url\0name\0removeFile\0index\0"
    "removeLastFile\0count\0getUrl\0getName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FolderListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       1,    1,   60,    2, 0x0a /* Public */,
       1,    1,   63,    2, 0x0a /* Public */,
       1,    2,   66,    2, 0x0a /* Public */,
       7,    1,   71,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x0a /* Public */,
      11,    1,   76,    2, 0x0a /* Public */,
      12,    1,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QUrl,    5,
    QMetaType::Void, QMetaType::QUrl, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::QUrl, QMetaType::Int,    8,
    QMetaType::QString, QMetaType::Int,    8,

       0        // eod
};

void FolderListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FolderListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addFile(); break;
        case 1: _t->addFile((*reinterpret_cast< AudioFile*(*)>(_a[1]))); break;
        case 2: _t->addFile((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 3: _t->addFile((*reinterpret_cast< const QUrl(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->removeFile((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->removeLastFile(); break;
        case 6: { int _r = _t->count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { QUrl _r = _t->getUrl((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 8: { QString _r = _t->getName((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AudioFile* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FolderListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_FolderListModel.data,
    qt_meta_data_FolderListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FolderListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FolderListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FolderListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int FolderListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
