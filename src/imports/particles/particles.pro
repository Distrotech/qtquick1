TARGET  = qmlparticlesplugin
TARGETPATH = QtQuick1/Qt/labs/particles
include(../qimportbase.pri)

QT += quick1 quick1-private core-private gui-private widgets-private

SOURCES += \
    qdeclarativeparticles.cpp \
    particles.cpp

HEADERS += \
    qdeclarativeparticles_p.h

OTHER_FILES += particles.json

DESTDIR = $$QT.quick1.imports/$$TARGETPATH
target.path = $$[QT_INSTALL_IMPORTS]/$$TARGETPATH

qmldir.files += $$PWD/qmldir
qmldir.path +=  $$[QT_INSTALL_IMPORTS]/$$TARGETPATH

symbian:{
    TARGET.UID3 = 0x2002131E
    
    isEmpty(DESTDIR):importFiles.files = qmlparticlesplugin$${QT_LIBINFIX}.dll qmldir
    else:importFiles.files = $$DESTDIR/qmlparticlesplugin$${QT_LIBINFIX}.dll qmldir
    importFiles.path = $$QT_IMPORTS_BASE_DIR/$$TARGETPATH

    DEPLOYMENT += importFiles
}

INSTALLS += target qmldir
