#-------------------------------------------------
#
# Project created by QtCreator 2018-11-24T23:17:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tsp_solver
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
    src/ui/mainwindow.cpp \
    src/adjacencymatrix.cpp \
    src/view_model/adjacencymatrixmodel.cpp \
    src/view_model/adjacencymatrixwidget.cpp \
    src/ui/adjacencymatrixmanagerwidget.cpp \
    src/utills/randomgenerator.cpp \
    src/algorithms/nearestneighbouralgorithm.cpp \
    src/ui/algorithmwidget.cpp \
    src/algorithms/simulatedannealingalgorithm.cpp \
    src/ui/algorithm_control_widgets/algorithmcontrolwidget.cpp \
    src/ui/algorithm_control_widgets/nearestneighbourcontrolwidget.cpp \
    src/ui/algorithm_control_widgets/simulatedannealingcontrolwidget.cpp \
    src/algorithms/antcolonyalgorithm.cpp

HEADERS += \
    src/ui/mainwindow.hpp \
    src/adjacencymatrix.hpp \
    src/view_model/adjacencymatrixmodel.hpp \
    src/view_model/adjacencymatrixwidget.hpp \
    src/ui/adjacencymatrixmanagerwidget.hpp \
    src/utills/randomgenerator.hpp \
    src/algorithms/tspalgorithm.hpp \
    src/algorithms/nearestneighbouralgorithm.hpp \
    src/ui/algorithmwidget.hpp \
    src/algorithms/simulatedannealingalgorithm.hpp \
    src/ui/algorithm_control_widgets/algorithmcontrolwidget.hpp \
    src/ui/algorithm_control_widgets/nearestneighbourcontrolwidget.hpp \
    src/ui/algorithm_control_widgets/simulatedannealingcontrolwidget.hpp \
    src/algorithms/antcolonyalgorithm.hpp

INCLUDEPATH += $$PWD/src
