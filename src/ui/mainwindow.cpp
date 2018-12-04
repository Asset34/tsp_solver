#include "mainwindow.hpp"

#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create matrix widget
    m_matrixWidget = new AdjacencyMatrixManagerWidget(5);

    // Create algorithm widget
    m_algorithmWidget = new AlgorithmWidget;

    // Create solve button
    m_solveButton = new QPushButton("Solve");

    // Create separator
    m_separator = new QFrame;
    m_separator->setFrameShape(QFrame::Shape::HLine);

    // Create algorithm layout
    m_algorithmLayout = new QVBoxLayout;
    m_algorithmLayout->setContentsMargins(0, 0, 0, 0);
    m_algorithmLayout->addWidget(m_solveButton);
    m_algorithmLayout->addWidget(m_separator);
    m_algorithmLayout->addWidget(m_algorithmWidget);

    // Create main layout
    m_mainlayout = new QHBoxLayout;
    m_mainlayout->setContentsMargins(0, 0, 0, 0);
    m_mainlayout->addWidget(m_matrixWidget, 2);
    m_mainlayout->addLayout(m_algorithmLayout, 1);

    // Create status bar label
    m_statusLabel = new QLabel;

    // Create status bar
    statusBar()->addPermanentWidget(m_statusLabel);

    // Create window
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(m_mainlayout);
    setCentralWidget(centralWidget);
    setContentsMargins(5, 5, 5, 5);

    // Create connections
    connect(m_solveButton, &QPushButton::clicked, this, &MainWindow::solve);
}

void MainWindow::setStatus(const QString &text)
{
    m_statusLabel->setText(text);
}

void MainWindow::solve()
{
    AdjacencyMatrix matrix = m_matrixWidget->getMatrix();
    if (!matrix.isValid()) {
        setStatus("Invalid graph");

        return;
    }

    setStatus("Solving ...");
    bool result = m_algorithmWidget->solve(matrix);
    if (!result) {
        setStatus("Invalid result");

        return;
    }

    setStatus("Success");
}
