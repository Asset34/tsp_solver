#include "mainwindow.hpp"

#include <QStatusBar>

#include <ui/widgets/tspsolverwidget.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_solverWidget = new TspSolverWidget;

    setCentralWidget(m_solverWidget);
    setContentsMargins(5, 5, 5, 5);

    connect(m_solverWidget, &TspSolverWidget::solvingStarted, this, &MainWindow::indicateStart);
    connect(m_solverWidget, &TspSolverWidget::solvingFinished, this, &MainWindow::indicateFinish);
}

void MainWindow::indicateStart()
{
    statusBar()->showMessage("Solving...");
}

void MainWindow::indicateFinish()
{
    statusBar()->clearMessage();
}
