#include "tspsolverwidget.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include <QVector>

#include <ui/graph_drawer/graphdrawerwidget.hpp>
#include <ui/tspalgorithmwidget.hpp>

TspSolverWidget::TspSolverWidget(QWidget *parent)
    : QWidget(parent)
{
    m_graphDrawerWidget = new GraphDrawerWidget;
    m_graphDrawerWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_algorithmWidget = new TspAlgorithmWidget;
    m_algorithmWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);

    m_solveButton = new QPushButton("Solve");

    m_algorithmLayout = new QVBoxLayout;
    m_algorithmLayout->setContentsMargins(0, 0, 0, 0);
    m_algorithmLayout->addWidget(m_algorithmWidget);
    m_algorithmLayout->addWidget(m_solveButton);

    m_mainlayout = new QHBoxLayout;
    m_mainlayout->setContentsMargins(0, 0, 0, 0);
    m_mainlayout->addWidget(m_graphDrawerWidget);
    m_mainlayout->addLayout(m_algorithmLayout);

    setLayout(m_mainlayout);

    connect(m_solveButton, &QPushButton::clicked, this, &TspSolverWidget::solve);
}

void TspSolverWidget::generate()
{
    m_graphDrawerWidget->generate();
}

void TspSolverWidget::clear()
{
    m_graphDrawerWidget->clear();
}

void TspSolverWidget::solve()
{
    AdjacencyMatrix matrix = m_graphDrawerWidget->getMatrix();
    TspResult result = m_algorithmWidget->execute(matrix);

    if (result.status) {
        m_graphDrawerWidget->setPath(QVector<int>::fromStdVector(result.tour));
    }
}
