#include "tspalgorithmwidget.hpp"

#include <QVBoxLayout>

#include <ui/boxes/tspalgorithmselectbox.hpp>
#include <parameter_list_widget/parameterlistwidget.hpp>

TspAlgorithmWidget::TspAlgorithmWidget(QWidget *parent)
    : QWidget(parent)
{
    m_algorithmSelectBox = new TspAlgorithmSelectBox;

    m_parameterListWidget = new ParameterListWidget;
    m_parameterListWidget->updateParameters(*m_algorithmSelectBox->getAlgorithm());

    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_algorithmSelectBox);
    m_layout->addWidget(m_parameterListWidget);

    setLayout(m_layout);

    connect(
        m_algorithmSelectBox,
        &TspAlgorithmSelectBox::algorithmChanged,
        this,
        &TspAlgorithmWidget::updateParameters
        );
}

void TspAlgorithmWidget::updateParameters(TspAlgorithm *algorithm)
{
    m_parameterListWidget->updateParameters(*algorithm);
}
