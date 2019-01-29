#include "mainwindow.hpp"

#include <ui/widgets/tspsolverwidget.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_solverWidget = new TspSolverWidget;

    setCentralWidget(m_solverWidget);
    setContentsMargins(5, 5, 5, 5);
}
