#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create matrix widget
    m_matrixWidget = new AdjacencyMatrixManagerWidget(5);

    // Create main layout
    m_mainlayout = new QHBoxLayout;
    m_mainlayout->setContentsMargins(0, 0, 0, 0);
    m_mainlayout->addWidget(m_matrixWidget);

    // Create window
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(m_mainlayout);
    setCentralWidget(centralWidget);
}
