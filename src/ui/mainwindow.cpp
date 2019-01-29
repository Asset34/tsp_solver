#include "mainwindow.hpp"

#include <QToolBar>

#include <ui/widgets/tspsolverwidget.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_solverWidget = new TspSolverWidget;

    QToolBar *toolBar = addToolBar("Main");
    QAction *solveAct = new QAction("Solve", this);
    connect(solveAct, &QAction::triggered, this, &MainWindow::solve);
    toolBar->addAction(solveAct);
    toolBar->setMovable(false);

    setCentralWidget(m_solverWidget);
    setContentsMargins(5, 5, 5, 5);
}

void MainWindow::solve()
{
    m_solverWidget->solve();
}
