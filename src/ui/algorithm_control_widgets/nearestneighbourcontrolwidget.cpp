#include "nearestneighbourcontrolwidget.hpp"

#include <QFormLayout>
#include <QHBoxLayout>

#include <QSpinBox>
#include <QCheckBox>

NearestNeighbourControlWidget::NearestNeighbourControlWidget(QWidget *parent)
    : AlgorithmControlWidget(parent)
{
    // Create spin box
    m_maxIterationsSpinBox = new QSpinBox;
    m_maxIterationsSpinBox->setRange(0, 1e9);
    m_maxIterationsSpinBox->setValue(0);
    m_maxIterationsSpinBox->setEnabled(false);

    // Create check box
    m_maxIterationsCheckBox = new QCheckBox;
    m_maxIterationsCheckBox->setChecked(false);
    m_maxIterationsCheckBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Create max iterations layout
    m_maxIterationsLayout = new QHBoxLayout;
    m_maxIterationsLayout->setContentsMargins(0, 0, 0, 0);
    m_maxIterationsLayout->addWidget(m_maxIterationsCheckBox);
    m_maxIterationsLayout->addWidget(m_maxIterationsSpinBox);

    // Create max iterations widget
    QWidget *maxIterationsWidget = new QWidget;
    maxIterationsWidget->setLayout(m_maxIterationsLayout);

    // Create main layout
    m_mainLayout = new QFormLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addRow("Max iteratons:", maxIterationsWidget);

    // Create widget
    setLayout(m_mainLayout);

    // Create connections
    connect(m_maxIterationsCheckBox, &QCheckBox::clicked,
            [this](bool checked){
        m_maxIterationsSpinBox->setEnabled(checked);
    });
}

TspAlgorithm::Parameters NearestNeighbourControlWidget::getParameters() const
{
    TspAlgorithm::Parameters p;
    p.maxIterations = m_maxIterationsSpinBox->value();
    p.maxIterationsFlag = m_maxIterationsCheckBox->isChecked();

    return p;
}
