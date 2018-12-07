#include "nearestneighbourcontrolwidget.hpp"

#include <QFormLayout>
#include <QSpinBox>

NearestNeighbourControlWidget::NearestNeighbourControlWidget(QWidget *parent)
    : AlgorithmControlWidget(parent)
{
    // Create spin box
    m_maxIterationsSpinBox = new QSpinBox;
    m_maxIterationsSpinBox->setRange(0, 1e9);
    m_maxIterationsSpinBox->setValue(1e9);

    // Create layout
    m_layout = new QFormLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addRow("Max iteratons:", m_maxIterationsSpinBox);

    // Crate widget
    setLayout(m_layout);
}

TspAlgorithm::Parameters NearestNeighbourControlWidget::getParameters() const
{
    TspAlgorithm::Parameters p;
    p.maxIterations = m_maxIterationsSpinBox->value();

    return p;
}
