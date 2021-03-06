#include "graphdrawerwidget.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QSpinBox>
#include <QPushButton>

#include "scrollablegraphdrawer.hpp"

GraphDrawerWidget::GraphDrawerWidget(QWidget *parent)
    : QWidget(parent)
{
    m_sizeSpinBox = new QSpinBox;
    m_sizeSpinBox->setRange(0, 1e9);
    m_sizeSpinBox->setValue(10);

    m_generateButton = new QPushButton("Generate");
    m_clearButton = new QPushButton("Clear");

    m_controlLayout = new QHBoxLayout;
    m_controlLayout->setContentsMargins(0, 0, 0, 0);
    m_controlLayout->addWidget(m_sizeSpinBox);
    m_controlLayout->addWidget(m_generateButton);
    m_controlLayout->addWidget(m_clearButton);
    m_controlLayout->addStretch(1);

    m_drawer = new ScrollableGraphDrawer;

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addWidget(m_drawer);
    m_mainLayout->addLayout(m_controlLayout);

    setLayout(m_mainLayout);

    connect(m_generateButton, &QPushButton::clicked, this, &GraphDrawerWidget::generate);
    connect(m_clearButton, &QPushButton::clicked, this, &GraphDrawerWidget::clear);
}

Matrix GraphDrawerWidget::getMatrix() const
{
    return m_drawer->getMatrix();
}

void GraphDrawerWidget::setTour(const Tour &tour)
{
    m_drawer->setTour(tour);
}

void GraphDrawerWidget::generate()
{
    int count = m_sizeSpinBox->value();
    m_drawer->generate(count);
}

void GraphDrawerWidget::clear()
{
    m_drawer->clear();
}
