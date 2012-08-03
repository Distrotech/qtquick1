CONFIG += testcase
testcase.timeout = 1200 # this is a slow test
TARGET = tst_qdeclarativexmlhttprequest

QT += testlib
contains(QT_CONFIG,quick1): QT += quick1 network
macx:CONFIG -= app_bundle

HEADERS += ../shared/testhttpserver.h

SOURCES += tst_qdeclarativexmlhttprequest.cpp \
           ../shared/testhttpserver.cpp

include(../shared/qdeclarativedatatest.pri)

win32:CONFIG+=insignificant_test # QTBUG-26703
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
