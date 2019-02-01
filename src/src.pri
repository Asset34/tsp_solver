QT += core gui widgets

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

include(parameterized_algorithm_qt/parameterized_algorithm_qt.pri)

SOURCES += \
    $$PWD/ui/mainwindow.cpp \
    $$PWD/utills/randomgenerator.cpp \
    $$PWD/algorithms/nearestneighbouralgorithm.cpp \
    $$PWD/algorithms/simulatedannealingalgorithm.cpp \
    $$PWD/algorithms/antcolonyalgorithm.cpp \
    $$PWD/ui/widgets/graph_drawer/graphdrawer.cpp \
    $$PWD/ui/widgets/graph_drawer/graphdrawerwidget.cpp \
    $$PWD/ui/widgets/graph_drawer/scrollablegraphdrawer.cpp \
    $$PWD/ui/widgets/tspalgorithmwidget.cpp \
    $$PWD/ui/widgets/tspresultwidget.cpp \
    $$PWD/ui/widgets/tspsolverwidget.cpp \
    $$PWD/matrix.cpp \
    $$PWD/tour.cpp \
    $$PWD/algorithms/ant.cpp \
    $$PWD/main.cpp

HEADERS += \
    $$PWD/ui/mainwindow.hpp \
    $$PWD/utills/randomgenerator.hpp \
    $$PWD/algorithms/tspalgorithm.hpp \
    $$PWD/algorithms/nearestneighbouralgorithm.hpp \
    $$PWD/algorithms/simulatedannealingalgorithm.hpp \
    $$PWD/algorithms/antcolonyalgorithm.hpp \
    $$PWD/ui/widgets/graph_drawer/graphdrawer.hpp \
    $$PWD/ui/widgets/graph_drawer/graphdrawerwidget.hpp \
    $$PWD/ui/widgets/graph_drawer/scrollablegraphdrawer.hpp \
    $$PWD/ui/widgets/tspalgorithmwidget.hpp \
    $$PWD/ui/widgets/tspresultwidget.hpp \
    $$PWD/ui/widgets/tspsolverwidget.hpp \
    $$PWD/matrix.hpp \
    $$PWD/tour.hpp \
