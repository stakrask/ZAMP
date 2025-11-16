/****************************************************************************
** Meta object code from reading C++ file 'frame.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../frame.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN9qglviewer5FrameE_t {};
} // unnamed namespace

template <> constexpr inline auto qglviewer::Frame::qt_create_metaobjectdata<qt_meta_tag_ZN9qglviewer5FrameE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qglviewer::Frame",
        "modified",
        "",
        "interpolated",
        "initFromDOMElement",
        "QDomElement",
        "element"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'modified'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'interpolated'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'initFromDOMElement'
        QtMocHelpers::SlotData<void(const QDomElement &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Frame, qt_meta_tag_ZN9qglviewer5FrameE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qglviewer::Frame::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer5FrameE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer5FrameE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9qglviewer5FrameE_t>.metaTypes,
    nullptr
} };

void qglviewer::Frame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Frame *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->modified(); break;
        case 1: _t->interpolated(); break;
        case 2: _t->initFromDOMElement((*reinterpret_cast< std::add_pointer_t<QDomElement>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Frame::*)()>(_a, &Frame::modified, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Frame::*)()>(_a, &Frame::interpolated, 1))
            return;
    }
}

const QMetaObject *qglviewer::Frame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qglviewer::Frame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer5FrameE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qglviewer::Frame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void qglviewer::Frame::modified()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qglviewer::Frame::interpolated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
