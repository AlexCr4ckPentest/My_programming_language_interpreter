TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    src/lexer.cpp \
    src/parser.cpp \
    src/token.cpp

HEADERS += \
    include/expressions/abstract_expression.h \
    include/expressions/binary_expression.h \
    include/expressions/number_expression.h \
    include/lexer.h \
    include/parser.h \
    include/token.h \
    include/token_char.h \
    include/token_types.h
