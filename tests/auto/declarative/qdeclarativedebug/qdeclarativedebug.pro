CONFIG += testcase
TARGET = tst_qdeclarativedebug

QT += testlib
contains(QT_CONFIG,quick1): QT += network quick1 quick1-private core-private script-private gui-private widgets-private
macx:CONFIG -= app_bundle

HEADERS += ../shared/debugutil_p.h
SOURCES += tst_qdeclarativedebug.cpp \
           ../shared/debugutil.cpp

CONFIG += parallel_test quick1_debug

