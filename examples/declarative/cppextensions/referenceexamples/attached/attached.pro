QT += declarative

SOURCES += main.cpp \
           person.cpp \
           birthdayparty.cpp 
HEADERS += person.h \
           birthdayparty.h
RESOURCES += attached.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/qtdeclarative/declarative/cppextensions/referenceexamples/attached
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS attached.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qtdeclarative/declarative/cppextensions/referenceexamples/attached
INSTALLS += target sources
