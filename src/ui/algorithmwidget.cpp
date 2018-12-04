#include "algorithmwidget.hpp"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>

#include "algorithms/nearestneighbouralgorithm.hpp"
#include "algorithms/simulatedannealingalgorithm.hpp"

AlgorithmWidget::AlgorithmWidget(QWidget *parent)
    : QWidget(parent),
      m_algorithm(nullptr)
{
    // Create algorithm combo box
    m_algorithmComboBox = new QComboBox;
    m_algorithmComboBox->addItem(QString::fromStdString(NearestNeighbourAlgorithm().getName()));
    m_algorithmComboBox->addItem(QString::fromStdString(SimulatedAnnealingAlgorithm().getName()));

    // Create labels
    m_lengthLabel = new QLabel;
    m_iterationsLabel = new QLabel;

    // Create form layout
    m_formLayout = new QFormLayout;
    m_formLayout->setContentsMargins(0, 0, 0, 0);
    m_formLayout->addRow("Algorithm: " , m_algorithmComboBox);
    m_formLayout->addRow("Length: "    , m_lengthLabel);
    m_formLayout->addRow("Iterations: ", m_iterationsLabel);

    // Create cycle text box
    m_cycleTextEdit = new QTextEdit;
    m_cycleTextEdit->setWordWrapMode(QTextOption::WordWrap);
    m_cycleTextEdit->setReadOnly(true);

    // Create main layout
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_formLayout);
    m_mainLayout->addWidget(m_cycleTextEdit);

    // Create widget
    setLayout(m_mainLayout);
}

AlgorithmWidget::~AlgorithmWidget()
{
    delete m_algorithm;
}

bool AlgorithmWidget::solve(const AdjacencyMatrix &matrix)
{
    resetAlgorithm();

    TspAlgorithm::Result result = m_algorithm->run(matrix);

    // Convert result parameters
    QString lengthStr = QString::number(result.length);
    QString iterationsStr = QString::number(result.iterations);
    QString cycleStr = buildCycleString(result.tour);

    // Set results
    m_lengthLabel->setText(lengthStr);
    m_iterationsLabel->setText(iterationsStr);
    m_cycleTextEdit->setText(cycleStr);

    return result.status;
}

QString AlgorithmWidget::buildCycleString(const std::vector<int> cycle) const
{
    if (!cycle.size()) {
        return QString();
    }

    QString cycleStr;

    cycleStr.append("(" + QString::number(cycle[0]) + ")");
    for (int i = 1; i < cycle.size(); i++) {
        cycleStr.append(" => ");
        cycleStr.append("(" + QString::number(cycle[i]) + ")");
    }

    return cycleStr;
}

void AlgorithmWidget::resetAlgorithm()
{
    delete m_algorithm;

    // Set algorithm
    int row = m_algorithmComboBox->currentIndex();
    switch (row) {
        case 0:
            m_algorithm = new NearestNeighbourAlgorithm;
        break;
        case 1:
            m_algorithm = new SimulatedAnnealingAlgorithm;
        break;
    }
}
