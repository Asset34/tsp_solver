#include "graphdrawermanager.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QSpinBox>
#include <QPushButton>

#include "scrollablegraphdrawer.hpp"

GraphDrawerManager::GraphDrawerManager(QWidget *parent)
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

    connect(m_generateButton, &QPushButton::clicked, this, &GraphDrawerManager::generate);
    connect(m_clearButton, &QPushButton::clicked, this, &GraphDrawerManager::clear);
}

AdjacencyMatrix GraphDrawerManager::getMatrix() const
{
    return m_drawer->getMatrix();
}

void GraphDrawerManager::setPath(const QVector<int> &numbers)
{
    m_drawer->setPath(numbers);
}

void GraphDrawerManager::generate()
{
    int count = m_sizeSpinBox->value();
    m_drawer->generate(count);
}

void GraphDrawerManager::clear()
{
    m_drawer->clear();
}
