#include "tspsolverwidget.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>

#include <memory>

#include <ui/widgets/graph_drawer/graphdrawerwidget.hpp>
#include <ui/widgets/tspalgorithmwidget.hpp>
#include <ui/widgets/tspresultwidget.hpp>

#include <algorithms/nearestneighbouralgorithm.hpp>
#include <algorithms/simulatedannealingalgorithm.hpp>
#include <algorithms/antcolonyalgorithm.hpp>

TspSolverWidget::TspSolverWidget(QWidget *parent)
    : QWidget(parent)
{
    m_graphDrawerWidget = new GraphDrawerWidget;
    m_graphDrawerWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_algorithmWidget = new TspAlgorithmWidget;
    m_algorithmWidget->setFixedWidth(250);
    m_algorithmWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    m_algorithmWidget->addAlgorithm(std::unique_ptr<Algorithm>(new NearestNeighbourAlgorithm));
    m_algorithmWidget->addAlgorithm(std::unique_ptr<Algorithm>(new SimulatedAnnealingAlgorithm));
    m_algorithmWidget->addAlgorithm(std::unique_ptr<Algorithm>(new AntColonyAlgorithm));

    m_resultWidget = new TspResultWidget;
    m_resultWidget->setFixedWidth(250);
    m_resultWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    QFrame *separator = new QFrame;
    separator->setFrameShape(QFrame::HLine);
    separator->setFrameShadow(QFrame::Raised);

    m_panelsLayout = new QVBoxLayout;
    m_panelsLayout->setContentsMargins(0, 0, 0, 0);
    m_panelsLayout->addWidget(m_algorithmWidget);
    m_panelsLayout->addWidget(separator);
    m_panelsLayout->addWidget(m_resultWidget);

    m_mainlayout = new QHBoxLayout;
    m_mainlayout->setContentsMargins(0, 0, 0, 0);
    m_mainlayout->addWidget(m_graphDrawerWidget);
    m_mainlayout->addLayout(m_panelsLayout);

    setLayout(m_mainlayout);
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
    Matrix matrix = m_graphDrawerWidget->getMatrix();
    TspResult result = m_algorithmWidget->execute(matrix);

    m_graphDrawerWidget->setTour(result.tour);
}
