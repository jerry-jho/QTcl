HEADERS += \
 qtcl.h \
 qtclprivate.h

SOURCES += \
 qtcl.cpp \
 qtclprivate.cpp

QT -= gui
TARGET = qtcl
TEMPLATE = lib
LIBS += -ltcl
