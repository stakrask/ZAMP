/****************************************************************************
** Meta object code from reading C++ file 'manipulatedFrame.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../manipulatedFrame.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manipulatedFrame.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9qglviewer16ManipulatedFrameE_t {};
} // unnamed namespace

template <> constexpr inline auto qglviewer::ManipulatedFrame::qt_create_metaobjectdata<qt_meta_tag_ZN9qglviewer16ManipulatedFrameE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qglviewer::ManipulatedFrame",
        "manipulated",
        "",
        "spun",
        "setRotationSensitivity",
        "sensitivity",
        "setTranslationSensitivity",
        "setSpinningSensitivity",
        "setWheelSensitivity",
        "setZoomSensitivity",
        "setSpinningQuaternion",
        "Quaternion",
        "spinningQuaternion",
        "startSpinning",
        "updateInterval",
        "stopSpinning",
        "spin",
        "spinUpdate",
        "initFromDOMElement",
        "QDomElement",
        "element"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'manipulated'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'spun'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setRotationSensitivity'
        QtMocHelpers::SlotData<void(qreal)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 5 },
        }}),
        // Slot 'setTranslationSensitivity'
        QtMocHelpers::SlotData<void(qreal)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 5 },
        }}),
        // Slot 'setSpinningSensitivity'
        QtMocHelpers::SlotData<void(qreal)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 5 },
        }}),
        // Slot 'setWheelSensitivity'
        QtMocHelpers::SlotData<void(qreal)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 5 },
        }}),
        // Slot 'setZoomSensitivity'
        QtMocHelpers::SlotData<void(qreal)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 5 },
        }}),
        // Slot 'setSpinningQuaternion'
        QtMocHelpers::SlotData<void(const Quaternion &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Slot 'startSpinning'
        QtMocHelpers::SlotData<void(int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'stopSpinning'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'spin'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'spinUpdate'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'initFromDOMElement'
        QtMocHelpers::SlotData<void(const QDomElement &)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 19, 20 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ManipulatedFrame, qt_meta_tag_ZN9qglviewer16ManipulatedFrameE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qglviewer::ManipulatedFrame::staticMetaObject = { {
    QMetaObject::SuperData::link<Frame::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer16ManipulatedFrameE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer16ManipulatedFrameE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9qglviewer16ManipulatedFrameE_t>.metaTypes,
    nullptr
} };

void qglviewer::ManipulatedFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ManipulatedFrame *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->manipulated(); break;
        case 1: _t->spun(); break;
        case 2: _t->setRotationSensitivity((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 3: _t->setTranslationSensitivity((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 4: _t->setSpinningSensitivity((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 5: _t->setWheelSensitivity((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 6: _t->setZoomSensitivity((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 7: _t->setSpinningQuaternion((*reinterpret_cast< std::add_pointer_t<Quaternion>>(_a[1]))); break;
        case 8: _t->startSpinning((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->stopSpinning(); break;
        case 10: _t->spin(); break;
        case 11: _t->spinUpdate(); break;
        case 12: _t->initFromDOMElement((*reinterpret_cast< std::add_pointer_t<QDomElement>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ManipulatedFrame::*)()>(_a, &ManipulatedFrame::manipulated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ManipulatedFrame::*)()>(_a, &ManipulatedFrame::spun, 1))
            return;
    }
}

const QMetaObject *qglviewer::ManipulatedFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qglviewer::ManipulatedFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer16ManipulatedFrameE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "MouseGrabber"))
        return static_cast< MouseGrabber*>(this);
    return Frame::qt_metacast(_clname);
}

int qglviewer::ManipulatedFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Frame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void qglviewer::ManipulatedFrame::manipulated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qglviewer::ManipulatedFrame::spun()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
