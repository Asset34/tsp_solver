#include "tspalgorithmwidget.hpp"

#include <QVBoxLayout>

#include <QGroupBox>

#include <QPushButton>

#include <ui/boxes/tspalgorithmselectbox.hpp>
#include <parameter_list_widget/parameterlistwidget.hpp>
#include <ui/tspresultwidget.hpp>

TspAlgorithmWidget::TspAlgorithmWidget(QWidget *parent)
    : QWidget(parent),
      m_lastResult{.status = false}
{
    m_algorithmSelectBox = new TspAlgorithmSelectBox;

    // Set default algorithm
    m_currentAlgorithm = m_algorithmSelectBox->getAlgorithm();

    // Create parameter list widget with appropriate QGroupBox and QLayout
    m_parameterListWidget = new ParameterListWidget;
    m_parameterListWidget->updateWith(*m_currentAlgorithm);
    QGroupBox *inputGroupBox = new QGroupBox("Input");
    QVBoxLayout *inputLayout = new QVBoxLayout;
    inputLayout->setContentsMargins(5, 0, 5, 0);
    inputLayout->addWidget(m_parameterListWidget);
    inputGroupBox->setLayout(inputLayout);

    // Create result widget with appropriate QGroupBox and QLayout
    m_resultWidget = new TspResultWidget;
    QGroupBox *resultGroupBox = new QGroupBox("Result");
    QVBoxLayout *resultLayout = new QVBoxLayout;
    resultLayout->setContentsMargins(5, 0, 5, 0);
    resultLayout->addWidget(m_resultWidget);
    resultGroupBox->setLayout(resultLayout);

    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_algorithmSelectBox);
    m_layout->addWidget(inputGroupBox);
    m_layout->addWidget(resultGroupBox);

    setLayout(m_layout);

    connect(
        m_algorithmSelectBox,
        &TspAlgorithmSelectBox::algorithmChanged,
        this,
        &TspAlgorithmWidget::changeAlgorithm
        );
}

const TspResult &TspAlgorithmWidget::getResult() const
{
    return m_lastResult;
}

void TspAlgorithmWidget::changeAlgorithm(TspAlgorithm *algorithm)
{
    m_currentAlgorithm = algorithm;
    m_parameterListWidget->updateWith(*algorithm);
}

void TspAlgorithmWidget::execute(const AdjacencyMatrix &matrix)
{
    TspResult result = m_currentAlgorithm->execute(matrix);

    m_lastResult = result;
    m_resultWidget->setResult(result);

    emit executed();
}
