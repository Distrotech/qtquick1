CONFIG += testcase
TARGET = tst_qdeclarativepixmapcache

QT += testlib
contains(QT_CONFIG,quick1): QT += concurrent quick1 quick1-private network
macx:CONFIG -= app_bundle

SOURCES += tst_qdeclarativepixmapcache.cpp

INCLUDEPATH += ../shared/
HEADERS += ../shared/testhttpserver.h
SOURCES += ../shared/testhttpserver.cpp

DEFINES += SRCDIR=\\\"$$PWD\\\"

# QMAKE_CXXFLAGS = -fprofile-arcs -ftest-coverage
# LIBS += -lgcov
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
