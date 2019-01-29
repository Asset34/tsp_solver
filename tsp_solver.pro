#-------------------------------------------------
#
# Project created by QtCreator 2018-11-24T23:17:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tsp_solver
TEMPLATE = app

CONFIG -= app_bundle
CONFIG += c++11

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
    src/utills/randomgenerator.cpp \
    src/algorithms/nearestneighbouralgorithm.cpp \
    src/algorithms/simulatedannealingalgorithm.cpp \
    src/algorithms/antcolonyalgorithm.cpp \
    src/ui/widgets/graph_drawer/graphdrawer.cpp \
    src/ui/widgets/graph_drawer/graphdrawerwidget.cpp \
    src/ui/widgets/graph_drawer/scrollablegraphdrawer.cpp \
    src/ui/widgets/tspalgorithmwidget.cpp \
    src/ui/widgets/tspresultwidget.cpp \
    src/ui/widgets/tspsolverwidget.cpp \
    src/matrix.cpp \
    src/tour.cpp \
    src/algorithms/ant.cpp \
    src/parameterized_algorithm_qt/core/parameters/flagparameter.cpp \
    src/parameterized_algorithm_qt/core/parameters/intparameter.cpp \
    src/parameterized_algorithm_qt/core/parameters/parameter.cpp \
    src/parameterized_algorithm_qt/core/parameters/realparameter.cpp \
    src/parameterized_algorithm_qt/widgets/algorithmselector.cpp \
    src/parameterized_algorithm_qt/widgets/algorithmwidget.cpp \
    src/parameterized_algorithm_qt/widgets/guicreatingvisitor.cpp \
    src/parameterized_algorithm_qt/widgets/parameterlistwidget.cpp

HEADERS += \
    src/ui/mainwindow.hpp \
    src/utills/randomgenerator.hpp \
    src/algorithms/tspalgorithm.hpp \
    src/algorithms/nearestneighbouralgorithm.hpp \
    src/algorithms/simulatedannealingalgorithm.hpp \
    src/algorithms/antcolonyalgorithm.hpp \
    src/ui/widgets/graph_drawer/graphdrawer.hpp \
    src/ui/widgets/graph_drawer/graphdrawerwidget.hpp \
    src/ui/widgets/graph_drawer/scrollablegraphdrawer.hpp \
    src/ui/widgets/tspalgorithmwidget.hpp \
    src/ui/widgets/tspresultwidget.hpp \
    src/ui/widgets/tspsolverwidget.hpp \
    src/matrix.hpp \
    src/tour.hpp \
    src/parameterized_algorithm_qt/core/parameters/flagparameter.hpp \
    src/parameterized_algorithm_qt/core/parameters/intparameter.hpp \
    src/parameterized_algorithm_qt/core/parameters/parameter.hpp \
    src/parameterized_algorithm_qt/core/parameters/realparameter.hpp \
    src/parameterized_algorithm_qt/core/algorithm.hpp \
    src/parameterized_algorithm_qt/core/parametervisitor.hpp \
    src/parameterized_algorithm_qt/widgets/algorithmselector.hpp \
    src/parameterized_algorithm_qt/widgets/algorithmwidget.hpp \
    src/parameterized_algorithm_qt/widgets/guicreatingvisitor.hpp \
    src/parameterized_algorithm_qt/widgets/parameterlistwidget.hpp

INCLUDEPATH += $$PWD/src
