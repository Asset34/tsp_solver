#include "tspalgorithmwidget.hpp"

#include <QVBoxLayout>

#include <QGroupBox>

#include <memory>

#include <parameterized_algorithm_qt/widgets/algorithmwidget.hpp>
#include <ui/widgets/tspresultwidget.hpp>

#include <algorithms/nearestneighbouralgorithm.hpp>
#include <algorithms/simulatedannealingalgorithm.hpp>
#include <algorithms/antcolonyalgorithm.hpp>

TspAlgorithmWidget::TspAlgorithmWidget(QWidget *parent)
    : QWidget(parent)
{
    // Create algorithm widget with appropriate groupbox and layout
    m_algorithmWidget = new AlgorithmWidget;
    QGroupBox *inputGroupBox = new QGroupBox("Input");
    QVBoxLayout *inputLayout = new QVBoxLayout;
    inputLayout->setContentsMargins(5, 0, 5, 5);
    inputLayout->addWidget(m_algorithmWidget);
    inputGroupBox->setLayout(inputLayout);

    // Create result widget with appropriate QGroupBox and QLayout
    m_resultWidget = new TspResultWidget;
    QGroupBox *resultGroupBox = new QGroupBox("Result");
    QVBoxLayout *resultLayout = new QVBoxLayout;
    resultLayout->setContentsMargins(5, 0, 5, 5);
    resultLayout->addWidget(m_resultWidget);
    resultGroupBox->setLayout(resultLayout);

    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(inputGroupBox);
    m_layout->addWidget(resultGroupBox);

    setLayout(m_layout);

    // Add algorithms
    m_algorithmWidget->addAlgorithm(std::unique_ptr<Algorithm>(new NearestNeighbourAlgorithm)  );
    m_algorithmWidget->addAlgorithm(std::unique_ptr<Algorithm>(new SimulatedAnnealingAlgorithm));
    m_algorithmWidget->addAlgorithm(std::unique_ptr<Algorithm>(new AntColonyAlgorithm)         );
}

TspResult TspAlgorithmWidget::execute(const Matrix &adjacencyMatrix)
{
//    TspResult result = m_currentAlgorithm->execute(adjacencyMatrix);
//    m_resultWidget->setResult(result);

//    return result;
}
