QT += declarative

SOURCES += main.cpp \
           person.cpp \
           birthdayparty.cpp 
HEADERS += person.h \
           birthdayparty.h
RESOURCES += grouped.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/qtdeclarative/declarative/cppextensions/referenceexamples/grouped
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS grouped.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qtdeclarative/declarative/cppextensions/referenceexamples/grouped
INSTALLS += target sources
