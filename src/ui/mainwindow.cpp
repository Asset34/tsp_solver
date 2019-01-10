#include "mainwindow.hpp"

#include <QDockWidget>

#include <ui/graph_drawer/graphdrawermanager.hpp>
#include <ui/tspalgorithmwidget.hpp>
#include <ui/resultwidget.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_graphDrawerWidget = new GraphDrawerManager;
    m_algorithmWidget = new TspAlgorithmWidget;
    m_resultWidget = new ResultWidget;

    QDockWidget *algorithmDock = new QDockWidget("TSP Algorithm", this);
    algorithmDock->setContentsMargins(0, 0, 0, 0);
    algorithmDock->setWidget(m_algorithmWidget);

    QDockWidget *resultDock = new QDockWidget("Result", this);
    resultDock->setContentsMargins(0, 0, 0, 0);
    resultDock->setWidget(m_resultWidget);

    setWindowTitle("TSP Solver");
    setCentralWidget(m_graphDrawerWidget);
    addDockWidget(Qt::RightDockWidgetArea, algorithmDock);
    addDockWidget(Qt::RightDockWidgetArea, resultDock);
}
