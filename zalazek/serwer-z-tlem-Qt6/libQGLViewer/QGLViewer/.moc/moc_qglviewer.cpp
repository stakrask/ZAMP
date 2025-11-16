/****************************************************************************
** Meta object code from reading C++ file 'qglviewer.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qglviewer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qglviewer.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QGLViewerE_t {};
} // unnamed namespace

template <> constexpr inline auto QGLViewer::qt_create_metaobjectdata<qt_meta_tag_ZN9QGLViewerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGLViewer",
        "viewerInitialized",
        "",
        "drawNeeded",
        "drawFinished",
        "automatic",
        "animateNeeded",
        "helpRequired",
        "axisIsDrawnChanged",
        "drawn",
        "gridIsDrawnChanged",
        "FPSIsDisplayedChanged",
        "displayed",
        "textIsEnabledChanged",
        "enabled",
        "cameraIsEditedChanged",
        "edited",
        "stereoChanged",
        "on",
        "pointSelected",
        "const QMouseEvent*",
        "e",
        "mouseGrabberChanged",
        "qglviewer::MouseGrabber*",
        "mouseGrabber",
        "setAxisIsDrawn",
        "draw",
        "setGridIsDrawn",
        "setFPSIsDisplayed",
        "display",
        "setTextIsEnabled",
        "enable",
        "setCameraIsEdited",
        "edit",
        "toggleAxisIsDrawn",
        "toggleGridIsDrawn",
        "toggleFPSIsDisplayed",
        "toggleTextIsEnabled",
        "toggleCameraIsEdited",
        "setBackgroundColor",
        "color",
        "setForegroundColor",
        "setSceneRadius",
        "radius",
        "setSceneCenter",
        "qglviewer::Vec",
        "center",
        "setSceneBoundingBox",
        "min",
        "max",
        "showEntireScene",
        "setCamera",
        "qglviewer::Camera*",
        "camera",
        "setManipulatedFrame",
        "qglviewer::ManipulatedFrame*",
        "frame",
        "setMouseGrabber",
        "setFullScreen",
        "fullScreen",
        "setStereoDisplay",
        "stereo",
        "toggleFullScreen",
        "toggleStereoDisplay",
        "toggleCameraMode",
        "saveSnapshot",
        "overwrite",
        "fileName",
        "setSnapshotFileName",
        "name",
        "setSnapshotFormat",
        "format",
        "setSnapshotCounter",
        "counter",
        "setSnapshotQuality",
        "quality",
        "openSnapshotFormatDialog",
        "snapshotToClipboard",
        "copyBufferToTexture",
        "GLint",
        "internalFormat",
        "GLenum",
        "setAnimationPeriod",
        "period",
        "startAnimation",
        "stopAnimation",
        "animate",
        "toggleAnimation",
        "help",
        "aboutQGLViewer",
        "select",
        "event",
        "point",
        "setSelectBufferSize",
        "size",
        "setSelectRegionWidth",
        "width",
        "setSelectRegionHeight",
        "height",
        "setSelectedName",
        "id",
        "setShortcut",
        "KeyboardAction",
        "action",
        "key",
        "setKeyboardAccelerator",
        "setKeyDescription",
        "description",
        "clearShortcuts",
        "setKeyFrameKey",
        "index",
        "setPlayKeyFramePathStateKey",
        "buttonState",
        "setPlayPathStateKey",
        "setAddKeyFrameStateKey",
        "setPathKey",
        "setPlayPathKeyboardModifiers",
        "Qt::KeyboardModifiers",
        "modifiers",
        "setAddKeyFrameKeyboardModifiers",
        "setMouseBinding",
        "state",
        "MouseHandler",
        "handler",
        "MouseAction",
        "withConstraint",
        "ClickAction",
        "doubleClick",
        "Qt::MouseButtons",
        "buttonsBefore",
        "setMouseBindingDescription",
        "Qt::MouseButton",
        "buttons",
        "button",
        "setWheelBinding",
        "Qt::Key",
        "clearMouseBindings",
        "wheelAction",
        "wheelHandler",
        "setHandlerKeyboardModifiers",
        "setHandlerStateKey",
        "setMouseStateKey",
        "initFromDOMElement",
        "QDomElement",
        "element",
        "saveStateToFile",
        "restoreStateFromFile",
        "setStateFileName",
        "saveToFile",
        "restoreFromFile",
        "resetVisualHints",
        "delayedFullScreen",
        "hideMessage"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'viewerInitialized'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'drawNeeded'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'drawFinished'
        QtMocHelpers::SignalData<void(bool)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 },
        }}),
        // Signal 'animateNeeded'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'helpRequired'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'axisIsDrawnChanged'
        QtMocHelpers::SignalData<void(bool)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Signal 'gridIsDrawnChanged'
        QtMocHelpers::SignalData<void(bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Signal 'FPSIsDisplayedChanged'
        QtMocHelpers::SignalData<void(bool)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 12 },
        }}),
        // Signal 'textIsEnabledChanged'
        QtMocHelpers::SignalData<void(bool)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 14 },
        }}),
        // Signal 'cameraIsEditedChanged'
        QtMocHelpers::SignalData<void(bool)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 16 },
        }}),
        // Signal 'stereoChanged'
        QtMocHelpers::SignalData<void(bool)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 18 },
        }}),
        // Signal 'pointSelected'
        QtMocHelpers::SignalData<void(const QMouseEvent *)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 21 },
        }}),
        // Signal 'mouseGrabberChanged'
        QtMocHelpers::SignalData<void(qglviewer::MouseGrabber *)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 23, 24 },
        }}),
        // Slot 'setAxisIsDrawn'
        QtMocHelpers::SlotData<void(bool)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 26 },
        }}),
        // Slot 'setAxisIsDrawn'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'setGridIsDrawn'
        QtMocHelpers::SlotData<void(bool)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 26 },
        }}),
        // Slot 'setGridIsDrawn'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'setFPSIsDisplayed'
        QtMocHelpers::SlotData<void(bool)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 29 },
        }}),
        // Slot 'setFPSIsDisplayed'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'setTextIsEnabled'
        QtMocHelpers::SlotData<void(bool)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 31 },
        }}),
        // Slot 'setTextIsEnabled'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'setCameraIsEdited'
        QtMocHelpers::SlotData<void(bool)>(32, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 33 },
        }}),
        // Slot 'setCameraIsEdited'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'toggleAxisIsDrawn'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleGridIsDrawn'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleFPSIsDisplayed'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleTextIsEnabled'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleCameraIsEdited'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setBackgroundColor'
        QtMocHelpers::SlotData<void(const QColor &)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QColor, 40 },
        }}),
        // Slot 'setForegroundColor'
        QtMocHelpers::SlotData<void(const QColor &)>(41, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QColor, 40 },
        }}),
        // Slot 'setSceneRadius'
        QtMocHelpers::SlotData<void(qreal)>(42, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 43 },
        }}),
        // Slot 'setSceneCenter'
        QtMocHelpers::SlotData<void(const qglviewer::Vec &)>(44, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 45, 46 },
        }}),
        // Slot 'setSceneBoundingBox'
        QtMocHelpers::SlotData<void(const qglviewer::Vec &, const qglviewer::Vec &)>(47, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 45, 48 }, { 0x80000000 | 45, 49 },
        }}),
        // Slot 'showEntireScene'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setCamera'
        QtMocHelpers::SlotData<void(qglviewer::Camera * const)>(51, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 52, 53 },
        }}),
        // Slot 'setManipulatedFrame'
        QtMocHelpers::SlotData<void(qglviewer::ManipulatedFrame *)>(54, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 55, 56 },
        }}),
        // Slot 'setMouseGrabber'
        QtMocHelpers::SlotData<void(qglviewer::MouseGrabber *)>(57, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 23, 24 },
        }}),
        // Slot 'setFullScreen'
        QtMocHelpers::SlotData<void(bool)>(58, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 59 },
        }}),
        // Slot 'setFullScreen'
        QtMocHelpers::SlotData<void()>(58, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'setStereoDisplay'
        QtMocHelpers::SlotData<void(bool)>(60, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 61 },
        }}),
        // Slot 'setStereoDisplay'
        QtMocHelpers::SlotData<void()>(60, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'toggleFullScreen'
        QtMocHelpers::SlotData<void()>(62, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleStereoDisplay'
        QtMocHelpers::SlotData<void()>(63, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleCameraMode'
        QtMocHelpers::SlotData<void()>(64, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'saveSnapshot'
        QtMocHelpers::SlotData<void(bool, bool)>(65, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 }, { QMetaType::Bool, 66 },
        }}),
        // Slot 'saveSnapshot'
        QtMocHelpers::SlotData<void(bool)>(65, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::Bool, 5 },
        }}),
        // Slot 'saveSnapshot'
        QtMocHelpers::SlotData<void()>(65, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'saveSnapshot'
        QtMocHelpers::SlotData<void(const QString &, bool)>(65, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 67 }, { QMetaType::Bool, 66 },
        }}),
        // Slot 'saveSnapshot'
        QtMocHelpers::SlotData<void(const QString &)>(65, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QString, 67 },
        }}),
        // Slot 'setSnapshotFileName'
        QtMocHelpers::SlotData<void(const QString &)>(68, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 69 },
        }}),
        // Slot 'setSnapshotFormat'
        QtMocHelpers::SlotData<void(const QString &)>(70, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 71 },
        }}),
        // Slot 'setSnapshotCounter'
        QtMocHelpers::SlotData<void(int)>(72, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 73 },
        }}),
        // Slot 'setSnapshotQuality'
        QtMocHelpers::SlotData<void(int)>(74, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 75 },
        }}),
        // Slot 'openSnapshotFormatDialog'
        QtMocHelpers::SlotData<bool()>(76, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'snapshotToClipboard'
        QtMocHelpers::SlotData<void()>(77, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'copyBufferToTexture'
        QtMocHelpers::SlotData<void(GLint, GLenum)>(78, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 79, 80 }, { 0x80000000 | 81, 71 },
        }}),
        // Slot 'copyBufferToTexture'
        QtMocHelpers::SlotData<void(GLint)>(78, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 79, 80 },
        }}),
        // Slot 'setAnimationPeriod'
        QtMocHelpers::SlotData<void(int)>(82, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 83 },
        }}),
        // Slot 'startAnimation'
        QtMocHelpers::SlotData<void()>(84, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stopAnimation'
        QtMocHelpers::SlotData<void()>(85, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'animate'
        QtMocHelpers::SlotData<void()>(86, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleAnimation'
        QtMocHelpers::SlotData<void()>(87, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'help'
        QtMocHelpers::SlotData<void()>(88, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'aboutQGLViewer'
        QtMocHelpers::SlotData<void()>(89, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'select'
        QtMocHelpers::SlotData<void(const QMouseEvent *)>(90, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 91 },
        }}),
        // Slot 'select'
        QtMocHelpers::SlotData<void(const QPoint &)>(90, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPoint, 92 },
        }}),
        // Slot 'setSelectBufferSize'
        QtMocHelpers::SlotData<void(int)>(93, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 94 },
        }}),
        // Slot 'setSelectRegionWidth'
        QtMocHelpers::SlotData<void(int)>(95, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 96 },
        }}),
        // Slot 'setSelectRegionHeight'
        QtMocHelpers::SlotData<void(int)>(97, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 98 },
        }}),
        // Slot 'setSelectedName'
        QtMocHelpers::SlotData<void(int)>(99, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 100 },
        }}),
        // Slot 'setShortcut'
        QtMocHelpers::SlotData<void(KeyboardAction, unsigned int)>(101, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 102, 103 }, { QMetaType::UInt, 104 },
        }}),
        // Slot 'setKeyboardAccelerator'
        QtMocHelpers::SlotData<void(KeyboardAction, unsigned int)>(105, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 102, 103 }, { QMetaType::UInt, 104 },
        }}),
        // Slot 'setKeyDescription'
        QtMocHelpers::SlotData<void(unsigned int, QString)>(106, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 104 }, { QMetaType::QString, 107 },
        }}),
        // Slot 'clearShortcuts'
        QtMocHelpers::SlotData<void()>(108, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setKeyFrameKey'
        QtMocHelpers::SlotData<void(unsigned int, int)>(109, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 110 }, { QMetaType::Int, 104 },
        }}),
        // Slot 'setPlayKeyFramePathStateKey'
        QtMocHelpers::SlotData<void(unsigned int)>(111, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 112 },
        }}),
        // Slot 'setPlayPathStateKey'
        QtMocHelpers::SlotData<void(unsigned int)>(113, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 112 },
        }}),
        // Slot 'setAddKeyFrameStateKey'
        QtMocHelpers::SlotData<void(unsigned int)>(114, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 112 },
        }}),
        // Slot 'setPathKey'
        QtMocHelpers::SlotData<void(int, unsigned int)>(115, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 104 }, { QMetaType::UInt, 110 },
        }}),
        // Slot 'setPathKey'
        QtMocHelpers::SlotData<void(int)>(115, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::Int, 104 },
        }}),
        // Slot 'setPlayPathKeyboardModifiers'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers)>(116, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 117, 118 },
        }}),
        // Slot 'setAddKeyFrameKeyboardModifiers'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers)>(119, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 117, 118 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(unsigned int, MouseHandler, MouseAction, bool)>(120, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 121 }, { 0x80000000 | 122, 123 }, { 0x80000000 | 124, 103 }, { QMetaType::Bool, 125 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(unsigned int, MouseHandler, MouseAction)>(120, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::UInt, 121 }, { 0x80000000 | 122, 123 }, { 0x80000000 | 124, 103 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(unsigned int, ClickAction, bool, Qt::MouseButtons)>(120, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 121 }, { 0x80000000 | 126, 103 }, { QMetaType::Bool, 127 }, { 0x80000000 | 128, 129 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(unsigned int, ClickAction, bool)>(120, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::UInt, 121 }, { 0x80000000 | 126, 103 }, { QMetaType::Bool, 127 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(unsigned int, ClickAction)>(120, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::UInt, 121 }, { 0x80000000 | 126, 103 },
        }}),
        // Slot 'setMouseBindingDescription'
        QtMocHelpers::SlotData<void(unsigned int, QString, bool, Qt::MouseButtons)>(130, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 121 }, { QMetaType::QString, 107 }, { QMetaType::Bool, 127 }, { 0x80000000 | 128, 129 },
        }}),
        // Slot 'setMouseBindingDescription'
        QtMocHelpers::SlotData<void(unsigned int, QString, bool)>(130, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::UInt, 121 }, { QMetaType::QString, 107 }, { QMetaType::Bool, 127 },
        }}),
        // Slot 'setMouseBindingDescription'
        QtMocHelpers::SlotData<void(unsigned int, QString)>(130, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::UInt, 121 }, { QMetaType::QString, 107 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers, Qt::MouseButton, MouseHandler, MouseAction, bool)>(120, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 132 }, { 0x80000000 | 122, 123 }, { 0x80000000 | 124, 103 },
            { QMetaType::Bool, 125 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers, Qt::MouseButton, MouseHandler, MouseAction)>(120, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 132 }, { 0x80000000 | 122, 123 }, { 0x80000000 | 124, 103 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers, Qt::MouseButton, ClickAction, bool, Qt::MouseButtons)>(120, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { 0x80000000 | 126, 103 }, { QMetaType::Bool, 127 },
            { 0x80000000 | 128, 129 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers, Qt::MouseButton, ClickAction, bool)>(120, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { 0x80000000 | 126, 103 }, { QMetaType::Bool, 127 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers, Qt::MouseButton, ClickAction)>(120, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { 0x80000000 | 126, 103 },
        }}),
        // Slot 'setWheelBinding'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers, MouseHandler, MouseAction, bool)>(134, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 117, 118 }, { 0x80000000 | 122, 123 }, { 0x80000000 | 124, 103 }, { QMetaType::Bool, 125 },
        }}),
        // Slot 'setWheelBinding'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers, MouseHandler, MouseAction)>(134, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 117, 118 }, { 0x80000000 | 122, 123 }, { 0x80000000 | 124, 103 },
        }}),
        // Slot 'setMouseBindingDescription'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers, Qt::MouseButton, QString, bool, Qt::MouseButtons)>(130, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { QMetaType::QString, 107 }, { QMetaType::Bool, 127 },
            { 0x80000000 | 128, 129 },
        }}),
        // Slot 'setMouseBindingDescription'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers, Qt::MouseButton, QString, bool)>(130, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { QMetaType::QString, 107 }, { QMetaType::Bool, 127 },
        }}),
        // Slot 'setMouseBindingDescription'
        QtMocHelpers::SlotData<void(Qt::KeyboardModifiers, Qt::MouseButton, QString)>(130, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { QMetaType::QString, 107 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(Qt::Key, Qt::KeyboardModifiers, Qt::MouseButton, MouseHandler, MouseAction, bool)>(120, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 135, 104 }, { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 132 }, { 0x80000000 | 122, 123 },
            { 0x80000000 | 124, 103 }, { QMetaType::Bool, 125 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(Qt::Key, Qt::KeyboardModifiers, Qt::MouseButton, MouseHandler, MouseAction)>(120, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 135, 104 }, { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 132 }, { 0x80000000 | 122, 123 },
            { 0x80000000 | 124, 103 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(Qt::Key, Qt::KeyboardModifiers, Qt::MouseButton, ClickAction, bool, Qt::MouseButtons)>(120, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 135, 104 }, { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { 0x80000000 | 126, 103 },
            { QMetaType::Bool, 127 }, { 0x80000000 | 128, 129 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(Qt::Key, Qt::KeyboardModifiers, Qt::MouseButton, ClickAction, bool)>(120, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 135, 104 }, { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { 0x80000000 | 126, 103 },
            { QMetaType::Bool, 127 },
        }}),
        // Slot 'setMouseBinding'
        QtMocHelpers::SlotData<void(Qt::Key, Qt::KeyboardModifiers, Qt::MouseButton, ClickAction)>(120, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 135, 104 }, { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { 0x80000000 | 126, 103 },
        }}),
        // Slot 'setWheelBinding'
        QtMocHelpers::SlotData<void(Qt::Key, Qt::KeyboardModifiers, MouseHandler, MouseAction, bool)>(134, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 135, 104 }, { 0x80000000 | 117, 118 }, { 0x80000000 | 122, 123 }, { 0x80000000 | 124, 103 },
            { QMetaType::Bool, 125 },
        }}),
        // Slot 'setWheelBinding'
        QtMocHelpers::SlotData<void(Qt::Key, Qt::KeyboardModifiers, MouseHandler, MouseAction)>(134, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 135, 104 }, { 0x80000000 | 117, 118 }, { 0x80000000 | 122, 123 }, { 0x80000000 | 124, 103 },
        }}),
        // Slot 'setMouseBindingDescription'
        QtMocHelpers::SlotData<void(Qt::Key, Qt::KeyboardModifiers, Qt::MouseButton, QString, bool, Qt::MouseButtons)>(130, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 135, 104 }, { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { QMetaType::QString, 107 },
            { QMetaType::Bool, 127 }, { 0x80000000 | 128, 129 },
        }}),
        // Slot 'setMouseBindingDescription'
        QtMocHelpers::SlotData<void(Qt::Key, Qt::KeyboardModifiers, Qt::MouseButton, QString, bool)>(130, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 135, 104 }, { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { QMetaType::QString, 107 },
            { QMetaType::Bool, 127 },
        }}),
        // Slot 'setMouseBindingDescription'
        QtMocHelpers::SlotData<void(Qt::Key, Qt::KeyboardModifiers, Qt::MouseButton, QString)>(130, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 135, 104 }, { 0x80000000 | 117, 118 }, { 0x80000000 | 131, 133 }, { QMetaType::QString, 107 },
        }}),
        // Slot 'clearMouseBindings'
        QtMocHelpers::SlotData<void()>(136, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'wheelAction'
        QtMocHelpers::SlotData<MouseAction(Qt::KeyboardModifiers) const>(137, 2, QMC::AccessPublic, 0x80000000 | 124, {{
            { 0x80000000 | 117, 118 },
        }}),
        // Slot 'wheelHandler'
        QtMocHelpers::SlotData<int(Qt::KeyboardModifiers) const>(138, 2, QMC::AccessPublic, QMetaType::Int, {{
            { 0x80000000 | 117, 118 },
        }}),
        // Slot 'setHandlerKeyboardModifiers'
        QtMocHelpers::SlotData<void(MouseHandler, Qt::KeyboardModifiers)>(139, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 122, 123 }, { 0x80000000 | 117, 118 },
        }}),
        // Slot 'setHandlerStateKey'
        QtMocHelpers::SlotData<void(MouseHandler, unsigned int)>(140, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 122, 123 }, { QMetaType::UInt, 112 },
        }}),
        // Slot 'setMouseStateKey'
        QtMocHelpers::SlotData<void(MouseHandler, unsigned int)>(141, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 122, 123 }, { QMetaType::UInt, 112 },
        }}),
        // Slot 'initFromDOMElement'
        QtMocHelpers::SlotData<void(const QDomElement &)>(142, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 143, 144 },
        }}),
        // Slot 'saveStateToFile'
        QtMocHelpers::SlotData<void()>(145, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'restoreStateFromFile'
        QtMocHelpers::SlotData<bool()>(146, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'setStateFileName'
        QtMocHelpers::SlotData<void(const QString &)>(147, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 69 },
        }}),
        // Slot 'saveToFile'
        QtMocHelpers::SlotData<void(const QString &)>(148, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 67 },
        }}),
        // Slot 'saveToFile'
        QtMocHelpers::SlotData<void()>(148, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'restoreFromFile'
        QtMocHelpers::SlotData<bool(const QString &)>(149, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 67 },
        }}),
        // Slot 'restoreFromFile'
        QtMocHelpers::SlotData<bool()>(149, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool),
        // Slot 'resetVisualHints'
        QtMocHelpers::SlotData<void()>(150, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'delayedFullScreen'
        QtMocHelpers::SlotData<void()>(151, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'hideMessage'
        QtMocHelpers::SlotData<void()>(152, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGLViewer, qt_meta_tag_ZN9QGLViewerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGLViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QGLViewerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QGLViewerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QGLViewerE_t>.metaTypes,
    nullptr
} };

void QGLViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGLViewer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->viewerInitialized(); break;
        case 1: _t->drawNeeded(); break;
        case 2: _t->drawFinished((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->animateNeeded(); break;
        case 4: _t->helpRequired(); break;
        case 5: _t->axisIsDrawnChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->gridIsDrawnChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->FPSIsDisplayedChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->textIsEnabledChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->cameraIsEditedChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->stereoChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->pointSelected((*reinterpret_cast< std::add_pointer_t<const QMouseEvent*>>(_a[1]))); break;
        case 12: _t->mouseGrabberChanged((*reinterpret_cast< std::add_pointer_t<qglviewer::MouseGrabber*>>(_a[1]))); break;
        case 13: _t->setAxisIsDrawn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->setAxisIsDrawn(); break;
        case 15: _t->setGridIsDrawn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->setGridIsDrawn(); break;
        case 17: _t->setFPSIsDisplayed((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->setFPSIsDisplayed(); break;
        case 19: _t->setTextIsEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->setTextIsEnabled(); break;
        case 21: _t->setCameraIsEdited((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 22: _t->setCameraIsEdited(); break;
        case 23: _t->toggleAxisIsDrawn(); break;
        case 24: _t->toggleGridIsDrawn(); break;
        case 25: _t->toggleFPSIsDisplayed(); break;
        case 26: _t->toggleTextIsEnabled(); break;
        case 27: _t->toggleCameraIsEdited(); break;
        case 28: _t->setBackgroundColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 29: _t->setForegroundColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 30: _t->setSceneRadius((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 31: _t->setSceneCenter((*reinterpret_cast< std::add_pointer_t<qglviewer::Vec>>(_a[1]))); break;
        case 32: _t->setSceneBoundingBox((*reinterpret_cast< std::add_pointer_t<qglviewer::Vec>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qglviewer::Vec>>(_a[2]))); break;
        case 33: _t->showEntireScene(); break;
        case 34: _t->setCamera((*reinterpret_cast< std::add_pointer_t<qglviewer::Camera*>>(_a[1]))); break;
        case 35: _t->setManipulatedFrame((*reinterpret_cast< std::add_pointer_t<qglviewer::ManipulatedFrame*>>(_a[1]))); break;
        case 36: _t->setMouseGrabber((*reinterpret_cast< std::add_pointer_t<qglviewer::MouseGrabber*>>(_a[1]))); break;
        case 37: _t->setFullScreen((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 38: _t->setFullScreen(); break;
        case 39: _t->setStereoDisplay((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 40: _t->setStereoDisplay(); break;
        case 41: _t->toggleFullScreen(); break;
        case 42: _t->toggleStereoDisplay(); break;
        case 43: _t->toggleCameraMode(); break;
        case 44: _t->saveSnapshot((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 45: _t->saveSnapshot((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 46: _t->saveSnapshot(); break;
        case 47: _t->saveSnapshot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 48: _t->saveSnapshot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 49: _t->setSnapshotFileName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 50: _t->setSnapshotFormat((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 51: _t->setSnapshotCounter((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 52: _t->setSnapshotQuality((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 53: { bool _r = _t->openSnapshotFormatDialog();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 54: _t->snapshotToClipboard(); break;
        case 55: _t->copyBufferToTexture((*reinterpret_cast< std::add_pointer_t<GLint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<GLenum>>(_a[2]))); break;
        case 56: _t->copyBufferToTexture((*reinterpret_cast< std::add_pointer_t<GLint>>(_a[1]))); break;
        case 57: _t->setAnimationPeriod((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 58: _t->startAnimation(); break;
        case 59: _t->stopAnimation(); break;
        case 60: _t->animate(); break;
        case 61: _t->toggleAnimation(); break;
        case 62: _t->help(); break;
        case 63: _t->aboutQGLViewer(); break;
        case 64: _t->select((*reinterpret_cast< std::add_pointer_t<const QMouseEvent*>>(_a[1]))); break;
        case 65: _t->select((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 66: _t->setSelectBufferSize((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 67: _t->setSelectRegionWidth((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 68: _t->setSelectRegionHeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 69: _t->setSelectedName((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 70: _t->setShortcut((*reinterpret_cast< std::add_pointer_t<KeyboardAction>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 71: _t->setKeyboardAccelerator((*reinterpret_cast< std::add_pointer_t<KeyboardAction>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 72: _t->setKeyDescription((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 73: _t->clearShortcuts(); break;
        case 74: _t->setKeyFrameKey((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 75: _t->setPlayKeyFramePathStateKey((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 76: _t->setPlayPathStateKey((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 77: _t->setAddKeyFrameStateKey((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 78: _t->setPathKey((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 79: _t->setPathKey((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 80: _t->setPlayPathKeyboardModifiers((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1]))); break;
        case 81: _t->setAddKeyFrameKeyboardModifiers((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1]))); break;
        case 82: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<MouseAction>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 83: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<MouseAction>>(_a[3]))); break;
        case 84: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ClickAction>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButtons>>(_a[4]))); break;
        case 85: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ClickAction>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 86: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ClickAction>>(_a[2]))); break;
        case 87: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButtons>>(_a[4]))); break;
        case 88: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 89: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 90: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<MouseAction>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 91: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<MouseAction>>(_a[4]))); break;
        case 92: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ClickAction>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButtons>>(_a[5]))); break;
        case 93: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ClickAction>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 94: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ClickAction>>(_a[3]))); break;
        case 95: _t->setWheelBinding((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<MouseAction>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 96: _t->setWheelBinding((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<MouseAction>>(_a[3]))); break;
        case 97: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButtons>>(_a[5]))); break;
        case 98: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4]))); break;
        case 99: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 100: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<MouseAction>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[6]))); break;
        case 101: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<MouseAction>>(_a[5]))); break;
        case 102: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<ClickAction>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButtons>>(_a[6]))); break;
        case 103: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<ClickAction>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 104: _t->setMouseBinding((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<ClickAction>>(_a[4]))); break;
        case 105: _t->setWheelBinding((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<MouseAction>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 106: _t->setWheelBinding((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<MouseAction>>(_a[4]))); break;
        case 107: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButtons>>(_a[6]))); break;
        case 108: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[5]))); break;
        case 109: _t->setMouseBindingDescription((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 110: _t->clearMouseBindings(); break;
        case 111: { MouseAction _r = _t->wheelAction((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])));
            if (_a[0]) *reinterpret_cast< MouseAction*>(_a[0]) = std::move(_r); }  break;
        case 112: { int _r = _t->wheelHandler((*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 113: _t->setHandlerKeyboardModifiers((*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2]))); break;
        case 114: _t->setHandlerStateKey((*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 115: _t->setMouseStateKey((*reinterpret_cast< std::add_pointer_t<MouseHandler>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 116: _t->initFromDOMElement((*reinterpret_cast< std::add_pointer_t<QDomElement>>(_a[1]))); break;
        case 117: _t->saveStateToFile(); break;
        case 118: { bool _r = _t->restoreStateFromFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 119: _t->setStateFileName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 120: _t->saveToFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 121: _t->saveToFile(); break;
        case 122: { bool _r = _t->restoreFromFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 123: { bool _r = _t->restoreFromFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 124: _t->resetVisualHints(); break;
        case 125: _t->delayedFullScreen(); break;
        case 126: _t->hideMessage(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< qglviewer::Camera* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)()>(_a, &QGLViewer::viewerInitialized, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)()>(_a, &QGLViewer::drawNeeded, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)(bool )>(_a, &QGLViewer::drawFinished, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)()>(_a, &QGLViewer::animateNeeded, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)()>(_a, &QGLViewer::helpRequired, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)(bool )>(_a, &QGLViewer::axisIsDrawnChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)(bool )>(_a, &QGLViewer::gridIsDrawnChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)(bool )>(_a, &QGLViewer::FPSIsDisplayedChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)(bool )>(_a, &QGLViewer::textIsEnabledChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)(bool )>(_a, &QGLViewer::cameraIsEditedChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)(bool )>(_a, &QGLViewer::stereoChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)(const QMouseEvent * )>(_a, &QGLViewer::pointSelected, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGLViewer::*)(qglviewer::MouseGrabber * )>(_a, &QGLViewer::mouseGrabberChanged, 12))
            return;
    }
}

const QMetaObject *QGLViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGLViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QGLViewerE_t>.strings))
        return static_cast<void*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int QGLViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 127)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 127;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 127)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 127;
    }
    return _id;
}

// SIGNAL 0
void QGLViewer::viewerInitialized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGLViewer::drawNeeded()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QGLViewer::drawFinished(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QGLViewer::animateNeeded()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QGLViewer::helpRequired()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QGLViewer::axisIsDrawnChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QGLViewer::gridIsDrawnChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void QGLViewer::FPSIsDisplayedChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QGLViewer::textIsEnabledChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void QGLViewer::cameraIsEditedChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void QGLViewer::stereoChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void QGLViewer::pointSelected(const QMouseEvent * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void QGLViewer::mouseGrabberChanged(qglviewer::MouseGrabber * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}
QT_WARNING_POP
