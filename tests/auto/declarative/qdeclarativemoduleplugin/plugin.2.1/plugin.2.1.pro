TEMPLATE = lib
CONFIG += plugin
SOURCES = plugin.cpp
QT = core declarative
DESTDIR = ../imports/com/nokia/AutoTestQmlPluginType.2.1

include(../qmldir_copier.pri)

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
