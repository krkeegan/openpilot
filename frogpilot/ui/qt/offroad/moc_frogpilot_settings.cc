/****************************************************************************
** Meta object code from reading C++ file 'frogpilot_settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "frogpilot_settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frogpilot_settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrogPilotSettingsWindow_t {
    QByteArrayData data[10];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrogPilotSettingsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrogPilotSettingsWindow_t qt_meta_stringdata_FrogPilotSettingsWindow = {
    {
QT_MOC_LITERAL(0, 0, 23), // "FrogPilotSettingsWindow"
QT_MOC_LITERAL(1, 24, 13), // "closeSubPanel"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 16), // "closeSubSubPanel"
QT_MOC_LITERAL(4, 56, 9), // "openPanel"
QT_MOC_LITERAL(5, 66, 12), // "openSubPanel"
QT_MOC_LITERAL(6, 79, 15), // "openSubSubPanel"
QT_MOC_LITERAL(7, 95, 12), // "updateMetric"
QT_MOC_LITERAL(8, 108, 6), // "metric"
QT_MOC_LITERAL(9, 115, 7) // "bootRun"

    },
    "FrogPilotSettingsWindow\0closeSubPanel\0"
    "\0closeSubSubPanel\0openPanel\0openSubPanel\0"
    "openSubSubPanel\0updateMetric\0metric\0"
    "bootRun"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrogPilotSettingsWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    2,   54,    2, 0x06 /* Public */,
       7,    1,   59,    2, 0x26 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    8,    9,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void FrogPilotSettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrogPilotSettingsWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeSubPanel(); break;
        case 1: _t->closeSubSubPanel(); break;
        case 2: _t->openPanel(); break;
        case 3: _t->openSubPanel(); break;
        case 4: _t->openSubSubPanel(); break;
        case 5: _t->updateMetric((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->updateMetric((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::closeSubPanel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::closeSubSubPanel)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::openPanel)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::openSubPanel)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::openSubSubPanel)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (FrogPilotSettingsWindow::*)(bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrogPilotSettingsWindow::updateMetric)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrogPilotSettingsWindow::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_FrogPilotSettingsWindow.data,
    qt_meta_data_FrogPilotSettingsWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrogPilotSettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrogPilotSettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrogPilotSettingsWindow.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int FrogPilotSettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FrogPilotSettingsWindow::closeSubPanel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FrogPilotSettingsWindow::closeSubSubPanel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FrogPilotSettingsWindow::openPanel()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FrogPilotSettingsWindow::openSubPanel()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FrogPilotSettingsWindow::openSubSubPanel()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void FrogPilotSettingsWindow::updateMetric(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
