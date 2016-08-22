QT += core gui widgets

TARGET = StrangSplitting
TEMPLATE = app

CONFIG += c++14


SOURCES += main.cpp\
        MainWindow.cpp \
    Solver.cpp \
    InputParameters.cpp \
    IResultsWriter.cpp \
    ResultsMemoryWriter.cpp

HEADERS  += MainWindow.h \
    Solver.h \
    InputParameters.h \
    IResultsWriter.h \
    ResultsMemoryWriter.h

FORMS    += MainWindow.ui

LIBS += -LC:\Development\armadillo\bin -larmadillo

INCLUDEPATH += C:\Development\armadillo\include
DEPENDPATH += C:\Development\armadillo\include
