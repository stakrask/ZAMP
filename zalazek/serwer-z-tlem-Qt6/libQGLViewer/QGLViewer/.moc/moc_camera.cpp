/****************************************************************************
** Meta object code from reading C++ file 'camera.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../camera.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9qglviewer6CameraE_t {};
} // unnamed namespace

template <> constexpr inline auto qglviewer::Camera::qt_create_metaobjectdata<qt_meta_tag_ZN9qglviewer6CameraE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "qglviewer::Camera",
        "setPosition",
        "",
        "Vec",
        "pos",
        "setOrientation",
        "Quaternion",
        "q",
        "theta",
        "phi",
        "setUpVector",
        "up",
        "noMove",
        "setViewDirection",
        "direction",
        "lookAt",
        "target",
        "showEntireScene",
        "fitSphere",
        "center",
        "radius",
        "fitBoundingBox",
        "min",
        "max",
        "fitScreenRegion",
        "rectangle",
        "centerScene",
        "interpolateToZoomOnPixel",
        "pixel",
        "interpolateToFitScene",
        "interpolateTo",
        "Frame",
        "fr",
        "duration",
        "setType",
        "Type",
        "type",
        "setFieldOfView",
        "fov",
        "setHorizontalFieldOfView",
        "hfov",
        "setFOVToFitScene",
        "setAspectRatio",
        "aspect",
        "setScreenWidthAndHeight",
        "width",
        "height",
        "setDevicePixelRatio",
        "ratio",
        "setZNearCoefficient",
        "coef",
        "setZClippingCoefficient",
        "setSceneRadius",
        "setSceneCenter",
        "setSceneCenterFromPixel",
        "setSceneBoundingBox",
        "setPivotPoint",
        "point",
        "setPivotPointFromPixel",
        "setRevolveAroundPoint",
        "setRevolveAroundPointFromPixel",
        "setFrame",
        "ManipulatedCameraFrame*",
        "mcf",
        "setKeyFrameInterpolator",
        "i",
        "KeyFrameInterpolator*",
        "kfi",
        "addKeyFrameToPath",
        "playPath",
        "deletePath",
        "resetPath",
        "drawAllPaths",
        "setFlySpeed",
        "speed",
        "setIODistance",
        "distance",
        "setPhysicalDistanceToScreen",
        "setPhysicalScreenWidth",
        "setFocusDistance",
        "initFromDOMElement",
        "QDomElement",
        "element",
        "onFrameModified"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'setPosition'
        QtMocHelpers::SlotData<void(const Vec &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'setOrientation'
        QtMocHelpers::SlotData<void(const Quaternion &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Slot 'setOrientation'
        QtMocHelpers::SlotData<void(qreal, qreal)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 8 }, { QMetaType::QReal, 9 },
        }}),
        // Slot 'setUpVector'
        QtMocHelpers::SlotData<void(const Vec &, bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 11 }, { QMetaType::Bool, 12 },
        }}),
        // Slot 'setUpVector'
        QtMocHelpers::SlotData<void(const Vec &)>(10, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 11 },
        }}),
        // Slot 'setViewDirection'
        QtMocHelpers::SlotData<void(const Vec &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 14 },
        }}),
        // Slot 'lookAt'
        QtMocHelpers::SlotData<void(const Vec &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 16 },
        }}),
        // Slot 'showEntireScene'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'fitSphere'
        QtMocHelpers::SlotData<void(const Vec &, qreal)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 19 }, { QMetaType::QReal, 20 },
        }}),
        // Slot 'fitBoundingBox'
        QtMocHelpers::SlotData<void(const Vec &, const Vec &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 22 }, { 0x80000000 | 3, 23 },
        }}),
        // Slot 'fitScreenRegion'
        QtMocHelpers::SlotData<void(const QRect &)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRect, 25 },
        }}),
        // Slot 'centerScene'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'interpolateToZoomOnPixel'
        QtMocHelpers::SlotData<void(const QPoint &)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPoint, 28 },
        }}),
        // Slot 'interpolateToFitScene'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'interpolateTo'
        QtMocHelpers::SlotData<void(const Frame &, qreal)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 32 }, { QMetaType::QReal, 33 },
        }}),
        // Slot 'setType'
        QtMocHelpers::SlotData<void(Type)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 35, 36 },
        }}),
        // Slot 'setFieldOfView'
        QtMocHelpers::SlotData<void(qreal)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 38 },
        }}),
        // Slot 'setHorizontalFieldOfView'
        QtMocHelpers::SlotData<void(qreal)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 40 },
        }}),
        // Slot 'setFOVToFitScene'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setAspectRatio'
        QtMocHelpers::SlotData<void(qreal)>(42, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 43 },
        }}),
        // Slot 'setScreenWidthAndHeight'
        QtMocHelpers::SlotData<void(int, int)>(44, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 45 }, { QMetaType::Int, 46 },
        }}),
        // Slot 'setDevicePixelRatio'
        QtMocHelpers::SlotData<void(qreal)>(47, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 48 },
        }}),
        // Slot 'setZNearCoefficient'
        QtMocHelpers::SlotData<void(qreal)>(49, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 50 },
        }}),
        // Slot 'setZClippingCoefficient'
        QtMocHelpers::SlotData<void(qreal)>(51, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 50 },
        }}),
        // Slot 'setSceneRadius'
        QtMocHelpers::SlotData<void(qreal)>(52, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 20 },
        }}),
        // Slot 'setSceneCenter'
        QtMocHelpers::SlotData<void(const Vec &)>(53, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 19 },
        }}),
        // Slot 'setSceneCenterFromPixel'
        QtMocHelpers::SlotData<bool(const QPoint &)>(54, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QPoint, 28 },
        }}),
        // Slot 'setSceneBoundingBox'
        QtMocHelpers::SlotData<void(const Vec &, const Vec &)>(55, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 22 }, { 0x80000000 | 3, 23 },
        }}),
        // Slot 'setPivotPoint'
        QtMocHelpers::SlotData<void(const Vec &)>(56, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 57 },
        }}),
        // Slot 'setPivotPointFromPixel'
        QtMocHelpers::SlotData<bool(const QPoint &)>(58, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QPoint, 28 },
        }}),
        // Slot 'setRevolveAroundPoint'
        QtMocHelpers::SlotData<void(const Vec &)>(59, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 57 },
        }}),
        // Slot 'setRevolveAroundPointFromPixel'
        QtMocHelpers::SlotData<bool(const QPoint &)>(60, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QPoint, 28 },
        }}),
        // Slot 'setFrame'
        QtMocHelpers::SlotData<void(ManipulatedCameraFrame * const)>(61, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 62, 63 },
        }}),
        // Slot 'setKeyFrameInterpolator'
        QtMocHelpers::SlotData<void(unsigned int, KeyFrameInterpolator * const)>(64, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 65 }, { 0x80000000 | 66, 67 },
        }}),
        // Slot 'addKeyFrameToPath'
        QtMocHelpers::SlotData<void(unsigned int)>(68, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 65 },
        }}),
        // Slot 'playPath'
        QtMocHelpers::SlotData<void(unsigned int)>(69, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 65 },
        }}),
        // Slot 'deletePath'
        QtMocHelpers::SlotData<void(unsigned int)>(70, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 65 },
        }}),
        // Slot 'resetPath'
        QtMocHelpers::SlotData<void(unsigned int)>(71, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 65 },
        }}),
        // Slot 'drawAllPaths'
        QtMocHelpers::SlotData<void()>(72, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setFlySpeed'
        QtMocHelpers::SlotData<void(qreal)>(73, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 74 },
        }}),
        // Slot 'setIODistance'
        QtMocHelpers::SlotData<void(qreal)>(75, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 76 },
        }}),
        // Slot 'setPhysicalDistanceToScreen'
        QtMocHelpers::SlotData<void(qreal)>(77, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 76 },
        }}),
        // Slot 'setPhysicalScreenWidth'
        QtMocHelpers::SlotData<void(qreal)>(78, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 45 },
        }}),
        // Slot 'setFocusDistance'
        QtMocHelpers::SlotData<void(qreal)>(79, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 76 },
        }}),
        // Slot 'initFromDOMElement'
        QtMocHelpers::SlotData<void(const QDomElement &)>(80, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 81, 82 },
        }}),
        // Slot 'onFrameModified'
        QtMocHelpers::SlotData<void()>(83, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Camera, qt_meta_tag_ZN9qglviewer6CameraE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject qglviewer::Camera::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer6CameraE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer6CameraE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9qglviewer6CameraE_t>.metaTypes,
    nullptr
} };

void qglviewer::Camera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Camera *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->setPosition((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 1: _t->setOrientation((*reinterpret_cast< std::add_pointer_t<Quaternion>>(_a[1]))); break;
        case 2: _t->setOrientation((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 3: _t->setUpVector((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 4: _t->setUpVector((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 5: _t->setViewDirection((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 6: _t->lookAt((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 7: _t->showEntireScene(); break;
        case 8: _t->fitSphere((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 9: _t->fitBoundingBox((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Vec>>(_a[2]))); break;
        case 10: _t->fitScreenRegion((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 11: _t->centerScene(); break;
        case 12: _t->interpolateToZoomOnPixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 13: _t->interpolateToFitScene(); break;
        case 14: _t->interpolateTo((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2]))); break;
        case 15: _t->setType((*reinterpret_cast< std::add_pointer_t<Type>>(_a[1]))); break;
        case 16: _t->setFieldOfView((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 17: _t->setHorizontalFieldOfView((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 18: _t->setFOVToFitScene(); break;
        case 19: _t->setAspectRatio((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 20: _t->setScreenWidthAndHeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 21: _t->setDevicePixelRatio((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 22: _t->setZNearCoefficient((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 23: _t->setZClippingCoefficient((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 24: _t->setSceneRadius((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 25: _t->setSceneCenter((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 26: { bool _r = _t->setSceneCenterFromPixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->setSceneBoundingBox((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Vec>>(_a[2]))); break;
        case 28: _t->setPivotPoint((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 29: { bool _r = _t->setPivotPointFromPixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->setRevolveAroundPoint((*reinterpret_cast< std::add_pointer_t<Vec>>(_a[1]))); break;
        case 31: { bool _r = _t->setRevolveAroundPointFromPixel((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 32: _t->setFrame((*reinterpret_cast< std::add_pointer_t<ManipulatedCameraFrame*>>(_a[1]))); break;
        case 33: _t->setKeyFrameInterpolator((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<KeyFrameInterpolator*>>(_a[2]))); break;
        case 34: _t->addKeyFrameToPath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 35: _t->playPath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 36: _t->deletePath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 37: _t->resetPath((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 38: _t->drawAllPaths(); break;
        case 39: _t->setFlySpeed((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 40: _t->setIODistance((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 41: _t->setPhysicalDistanceToScreen((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 42: _t->setPhysicalScreenWidth((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 43: _t->setFocusDistance((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 44: _t->initFromDOMElement((*reinterpret_cast< std::add_pointer_t<QDomElement>>(_a[1]))); break;
        case 45: _t->onFrameModified(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< KeyFrameInterpolator* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *qglviewer::Camera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qglviewer::Camera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9qglviewer6CameraE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qglviewer::Camera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    }
    return _id;
}
QT_WARNING_POP
