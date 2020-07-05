TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        src/lexer.cpp \
        src/token.cpp

HEADERS += \
    include/lexer.h \
    include/token.h \
    include/token_types.h
