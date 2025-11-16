/****************************************************************************
** Meta object code from reading C++ file 'keyFrameInterpolator.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../keyFrameInterpolator.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyFrameInterpolator.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9qglviewer20KeyFrameInterpolatorE_t {};
} // unnamed namespace

template <> constexpr inline auto qglviewer::KeyFrameInterpolator::qt_create_metaobjectdata<qt_meta_tag_ZN9qglviewer20KeyFrameInterpolatorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qglviewer::KeyFrameInterpolator",
        "interpolated",
        "",
        "endReached",
        "addKeyFrame",
        "Frame",
        "frame",
        "time",
        "const Frame*",
        "deletePath",
        "setFrame",
        "Frame*",
        "setInterpolationTime",
        "setInterpolationSpeed",
        "speed",
        "setInterpolationPeriod",
        "period",
        "setLoopInterpolation",
        "loop",
        "setClosedPath",
        "closed",
        "startInterpolation",
        "stopInterpolation",
        "resetInterpolation",
        "toggleInterpolation",
        "interpolateAtTime",
        "update",
        "invalidateValues"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'interpolated'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'endReached'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'addKeyFrame'
        QtMocHelpers::SlotData<void(const Frame &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Slot 'addKeyFrame'
        QtMocHelpers::SlotData<void(const Frame &, qreal)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 }, { QMetaType::QReal, 7 },
        }}),
        // Slot 'addKeyFrame'
        QtMocHelpers::SlotData<void(const Frame * const)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 6 },
        }}),
        // Slot 'addKeyFrame'
        QtMocHelpers::SlotData<void(const Frame * const, qreal)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 6 }, { QMetaType::QReal, 7 },
        }}),
        // Slot 'deletePath'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setFrame'
        QtMocHelpers::SlotData<void(Frame * const)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 6 },
        }}),
        // Slot 'setInterpolationTime'
        QtMocHelpers::SlotData<void(qreal)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 7 },
        }}),
        // Slot 'setInterpolationSpeed'
        QtMocHelpers::SlotData<void(qreal)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 14 },
        }}),
        // Slot 'setInterpolationPeriod'
        QtMocHelpers::SlotData<void(int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Slot 'setLoopInterpolation'
        QtMocHelpers::SlotData<void(bool)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 18 },
        }}),
        // Slot 'setLoopInterpolation'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'setClosedPath'
        QtMocHelpers::SlotData<void(bool)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 20 },
        }}),
        // Slot 'setClosedPath'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'startInterpolation'
        QtMocHelpers::SlotData<void(int)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Slot 'startInterpolation'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'stopInterpolation'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resetInterpolation'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleInterpolation'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'interpolateAtTime'
        QtMocHelpers::SlotData<void(qreal)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 7 },
        }}),
        // Slot 'update'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'invalidateValues'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<KeyFrameInterpolator, qt_meta_tag_ZN9qglviewer20KeyFrameInterpolatorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qglviewer::KeyFrameInterpolator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer20KeyFrameInterpolatorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer20KeyFrameInterpolatorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9qglviewer20KeyFrameInterpolatorE_t>.metaTypes,
    nullptr
} };

void qglviewer::KeyFrameInterpolator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<KeyFrameInterpolator *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->interpolated(); break;
        case 1: _t->endReached(); break;
        case 2: _t->addKeyFrame((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1]))); break;
        case 3: _t->addKeyFrame((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 4: _t->addKeyFrame((*reinterpret_cast< std::add_pointer_t<const Frame*>>(_a[1]))); break;
        case 5: _t->addKeyFrame((*reinterpret_cast< std::add_pointer_t<const Frame*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 6: _t->deletePath(); break;
        case 7: _t->setFrame((*reinterpret_cast< std::add_pointer_t<Frame*>>(_a[1]))); break;
        case 8: _t->setInterpolationTime((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 9: _t->setInterpolationSpeed((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 10: _t->setInterpolationPeriod((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->setLoopInterpolation((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->setLoopInterpolation(); break;
        case 13: _t->setClosedPath((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->setClosedPath(); break;
        case 15: _t->startInterpolation((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->startInterpolation(); break;
        case 17: _t->stopInterpolation(); break;
        case 18: _t->resetInterpolation(); break;
        case 19: _t->toggleInterpolation(); break;
        case 20: _t->interpolateAtTime((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 21: _t->update(); break;
        case 22: _t->invalidateValues(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Frame* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (KeyFrameInterpolator::*)()>(_a, &KeyFrameInterpolator::interpolated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (KeyFrameInterpolator::*)()>(_a, &KeyFrameInterpolator::endReached, 1))
            return;
    }
}

const QMetaObject *qglviewer::KeyFrameInterpolator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qglviewer::KeyFrameInterpolator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer20KeyFrameInterpolatorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qglviewer::KeyFrameInterpolator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void qglviewer::KeyFrameInterpolator::interpolated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qglviewer::KeyFrameInterpolator::endReached()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
