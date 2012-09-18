TARGET = qmlshadersplugin
TARGETPATH = QtQuick1/Qt/labs/shaders
include(../qimportbase.pri)

QT += quick1 widgets opengl

SOURCES += \
    qmlshadersplugin_plugin.cpp \
    shadereffect.cpp \
    shadereffectitem.cpp \
    shadereffectsource.cpp \
    scenegraph/qsggeometry.cpp \
    shadereffectbuffer.cpp

HEADERS += \
    qmlshadersplugin_plugin.h \
    glfunctions.h \
    shadereffect.h \
    shadereffectitem.h \
    shadereffectsource.h \
    scenegraph/qsggeometry.h \
    shadereffectbuffer.h

OTHER_FILES += shaders.json

DESTDIR = $$QT.quick1.imports/$$TARGETPATH
target.path = $$[QT_INSTALL_IMPORTS]/$$TARGETPATH

qmldir.files += $$PWD/qmldir
qmldir.path +=  $$[QT_INSTALL_IMPORTS]/$$TARGETPATH

INSTALLS += target qmldir
