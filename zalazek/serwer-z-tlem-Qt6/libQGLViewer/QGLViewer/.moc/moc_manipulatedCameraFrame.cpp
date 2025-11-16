/****************************************************************************
** Meta object code from reading C++ file 'manipulatedCameraFrame.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../manipulatedCameraFrame.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manipulatedCameraFrame.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9qglviewer22ManipulatedCameraFrameE_t {};
} // unnamed namespace

template <> constexpr inline auto qglviewer::ManipulatedCameraFrame::qt_create_metaobjectdata<qt_meta_tag_ZN9qglviewer22ManipulatedCameraFrameE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qglviewer::ManipulatedCameraFrame",
        "setFlySpeed",
        "",
        "speed",
        "setSceneUpVector",
        "Vec",
        "up",
        "spin",
        "initFromDOMElement",
        "QDomElement",
        "element",
        "flyUpdate"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'setFlySpeed'
        QtMocHelpers::SlotData<void(qreal)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 3 },
        }}),
        // Slot 'setSceneUpVector'
        QtMocHelpers::SlotData<void(const Vec &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Slot 'spin'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'initFromDOMElement'
        QtMocHelpers::SlotData<void(const QDomElement &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Slot 'flyUpdate'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ManipulatedCameraFrame, qt_meta_tag_ZN9qglviewer22ManipulatedCameraFrameE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qglviewer::ManipulatedCameraFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<ManipulatedFrame::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer22ManipulatedCameraFrameE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer22ManipulatedCameraFrameE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9qglviewer22ManipulatedCameraFrameE_t>.metaTypes,
    nullptr
} };

void qglviewer::ManipulatedCameraFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ManipulatedCameraFrame *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->setFlySpeed((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 1: _t->setSceneUpVector((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 2: _t->spin(); break;
        case 3: _t->initFromDOMElement((*reinterpret_cast< std::add_pointer_t<QDomElement>>(_a[1]))); break;
        case 4: _t->flyUpdate(); break;
        default: ;
        }
    }
}

const QMetaObject *qglviewer::ManipulatedCameraFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qglviewer::ManipulatedCameraFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer22ManipulatedCameraFrameE_t>.strings))
        return static_cast<void*>(this);
    return ManipulatedFrame::qt_metacast(_clname);
}

int qglviewer::ManipulatedCameraFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ManipulatedFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
