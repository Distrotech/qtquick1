CONFIG += testcase
TARGET = tst_qdeclarativeviewer

QT += testlib
contains(QT_CONFIG,declarative): QT += declarative gui
macx:CONFIG -= app_bundle

include(../../../../tools/qml/qml.pri)

SOURCES += tst_qdeclarativeviewer.cpp

DEFINES += SRCDIR=\\\"$$PWD\\\"

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
