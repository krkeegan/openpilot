/****************************************************************************
** Meta object code from reading C++ file 'device_settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "device_settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device_settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrogPilotDevicePanel_t {
    QByteArrayData data[3];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrogPilotDevicePanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrogPilotDevicePanel_t qt_meta_stringdata_FrogPilotDevicePanel = {
    {
QT_MOC_LITERAL(0, 0, 20), // "FrogPilotDevicePanel"
QT_MOC_LITERAL(1, 21, 12), // "openSubPanel"
QT_MOC_LITERAL(2, 34, 0) // ""

    },
    "FrogPilotDevicePanel\0openSubPanel\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrogPilotDevicePanel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void FrogPilotDevicePanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrogPilotDevicePanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openSubPanel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrogPilotDevicePanel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotDevicePanel::openSubPanel)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FrogPilotDevicePanel::staticMetaObject = { {
    &FrogPilotListWidget::staticMetaObject,
    qt_meta_stringdata_FrogPilotDevicePanel.data,
    qt_meta_data_FrogPilotDevicePanel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrogPilotDevicePanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrogPilotDevicePanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrogPilotDevicePanel.stringdata0))
        return static_cast<void*>(this);
    return FrogPilotListWidget::qt_metacast(_clname);
}

int FrogPilotDevicePanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = FrogPilotListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void FrogPilotDevicePanel::openSubPanel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
