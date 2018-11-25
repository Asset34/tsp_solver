#include "adjacencymatrixmanagerwidget.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QPushButton>

#include "view_model/adjacencymatrixwidget.hpp"

AdjacencyMatrixManagerWidget::AdjacencyMatrixManagerWidget(int size, QWidget *parent)
    : QWidget(parent)
{
    // Create size spin box
    m_sizeSpinBox = new QSpinBox;
    m_sizeSpinBox->setRange(0, 10000);
    m_sizeSpinBox->setValue(size);

    // Create buttons
    m_generateButton = new QPushButton("Generate");
    m_clearButton = new QPushButton("Clear");

    // Create
    m_controlLayout = new QVBoxLayout;
    m_controlLayout->setContentsMargins(0, 0, 0, 0);
    m_controlLayout->addWidget(m_sizeSpinBox);
    m_controlLayout->addWidget(m_generateButton);
    m_controlLayout->addWidget(m_clearButton);
    m_controlLayout->addStretch(1);

    // Create
    m_matrixWidget = new AdjacencyMatrixWidget(size);

    // Create
    m_mainLayout = new QHBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_controlLayout);
    m_mainLayout->addWidget(m_matrixWidget);

    // Create
    setLayout(m_mainLayout);
    setContentsMargins(5, 5, 5, 5);

    // Create
    connect(
        m_sizeSpinBox,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        m_matrixWidget,
        &AdjacencyMatrixWidget::setSize
        );
    connect(m_generateButton, &QPushButton::clicked, this, &AdjacencyMatrixManagerWidget::generate);
    connect(m_clearButton, &QPushButton::clicked, this, &AdjacencyMatrixManagerWidget::clear);
}

const AdjacencyMatrix &AdjacencyMatrixManagerWidget::getMatrix() const
{
    return m_matrixWidget->getMatrix();
}

void AdjacencyMatrixManagerWidget::generate()
{
    m_matrixWidget->generate(GENERATOR_MIN, GENERATOR_MAX);
}

void AdjacencyMatrixManagerWidget::clear()
{
    m_matrixWidget->clear();
}
