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
    src/utills/randomgenerator.cpp \
    src/algorithms/nearestneighbouralgorithm.cpp \
    src/algorithms/simulatedannealingalgorithm.cpp \
    src/algorithms/antcolonyalgorithm.cpp \
    src/ui/graph_drawer/graphdrawer.cpp \
    src/ui/graph_drawer/graphdrawermanager.cpp \
    src/ui/graph_drawer/scrollablegraphdrawer.cpp \
    src/parameter_list_widget/parameterized_algorithm_base/Parameters/flagparameter.cpp \
    src/parameter_list_widget/parameterized_algorithm_base/Parameters/intparameter.cpp \
    src/parameter_list_widget/parameterized_algorithm_base/Parameters/parameter.cpp \
    src/parameter_list_widget/parameterized_algorithm_base/Parameters/realparameter.cpp \
    src/parameter_list_widget/guicreatingvisitor.cpp \
    src/parameter_list_widget/parameterlistwidget.cpp \
    src/ui/boxes/tspalgorithmselectbox.cpp \
    src/ui/tspalgorithmwidget.cpp

HEADERS += \
    src/ui/mainwindow.hpp \
    src/adjacencymatrix.hpp \
    src/utills/randomgenerator.hpp \
    src/algorithms/tspalgorithm.hpp \
    src/algorithms/nearestneighbouralgorithm.hpp \
    src/algorithms/simulatedannealingalgorithm.hpp \
    src/algorithms/antcolonyalgorithm.hpp \
    src/ui/graph_drawer/graphdrawer.hpp \
    src/ui/graph_drawer/graphdrawermanager.hpp \
    src/ui/graph_drawer/scrollablegraphdrawer.hpp \
    src/parameter_list_widget/parameterized_algorithm_base/Parameters/flagparameter.hpp \
    src/parameter_list_widget/parameterized_algorithm_base/Parameters/intparameter.hpp \
    src/parameter_list_widget/parameterized_algorithm_base/Parameters/parameter.hpp \
    src/parameter_list_widget/parameterized_algorithm_base/Parameters/realparameter.hpp \
    src/parameter_list_widget/parameterized_algorithm_base/algorithm.hpp \
    src/parameter_list_widget/parameterized_algorithm_base/parametervisitor.hpp \
    src/parameter_list_widget/guicreatingvisitor.hpp \
    src/parameter_list_widget/parameterlistwidget.hpp \
    src/ui/boxes/tspalgorithmselectbox.hpp \
    src/ui/tspalgorithmwidget.hpp

INCLUDEPATH += $$PWD/src
