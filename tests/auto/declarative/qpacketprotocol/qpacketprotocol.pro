CONFIG += testcase
TARGET = tst_qpacketprotocol

QT += testlib
contains(QT_CONFIG,quick1): QT += network quick1 quick1-private core-private gui-private widgets-private
macx:CONFIG -= app_bundle

HEADERS += ../shared/debugutil_p.h
SOURCES += tst_qpacketprotocol.cpp \
           ../shared/debugutil.cpp

CONFIG += parallel_test
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
