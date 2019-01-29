#include "mainwindow.hpp"

#include <QStatusBar>

#include <ui/widgets/tspsolverwidget.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_solverWidget = new TspSolverWidget;

    setCentralWidget(m_solverWidget);
    setContentsMargins(5, 5, 5, 5);

    connect(m_solverWidget, &TspSolverWidget::statusChanged, this, &MainWindow::indicateSolverStatus);
}

void MainWindow::indicateSolverStatus(QString status)
{
    statusBar()->showMessage(status);
}
