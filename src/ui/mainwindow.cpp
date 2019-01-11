#include "mainwindow.hpp"

#include <ui/widgets/tspsolverwidget.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_tspSolverWidget = new TspSolverWidget;

    setCentralWidget(m_tspSolverWidget);
    setContentsMargins(5, 5, 5, 5);
}
