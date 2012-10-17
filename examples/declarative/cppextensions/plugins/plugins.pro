TEMPLATE = lib
CONFIG += qt plugin
QT += widgets declarative

DESTDIR = com/nokia/TimeExample
TARGET  = qmlqtimeexampleplugin

SOURCES += plugin.cpp

OTHER_FILES += "plugin.json"

qdeclarativesources.files += \
    com/nokia/TimeExample/qmldir \
    com/nokia/TimeExample/center.png \
    com/nokia/TimeExample/clock.png \
    com/nokia/TimeExample/Clock.qml \
    com/nokia/TimeExample/hour.png \
    com/nokia/TimeExample/minute.png

qdeclarativesources.path += $$[QT_INSTALL_EXAMPLES]/qtdeclarative/declarative/cppextensions/plugins/com/nokia/TimeExample

sources.files += plugins.pro plugin.cpp plugins.qml README
sources.path += $$[QT_INSTALL_EXAMPLES]/qtdeclarative/declarative/cppextensions/plugins
target.path += $$[QT_INSTALL_EXAMPLES]/qtdeclarative/declarative/cppextensions/plugins/com/nokia/TimeExample

INSTALLS += qdeclarativesources sources target

