#include "algorithmwidget.hpp"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>

#include "algorithms/nearestneighbouralgorithm.hpp"

AlgorithmWidget::AlgorithmWidget(QWidget *parent)
    : QWidget(parent),
      m_algorithm(nullptr)
{
    // Create algorithm combo box
    m_algorithmComboBox = new QComboBox;
    m_algorithmComboBox->addItem(QString::fromStdString(NearestNeighbourAlgorithm().getName()));

    // Create length label
    m_lengthLabel = new QLabel;

    // Create form layout
    m_formLayout = new QFormLayout;
    m_formLayout->setContentsMargins(0, 0, 0, 0);
    m_formLayout->addRow("Algorithm: ", m_algorithmComboBox);
    m_formLayout->addRow("Length: ", m_lengthLabel);

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

bool AlgorithmWidget::solve(const AdjacencyMatrix &matrix)
{
    resetAlgorithm();

    TspAlgorithm::Result result = m_algorithm->run(matrix);

    QString lengthStr = QString::number(result.length);
    QString cycleStr = buildCycleString(result.cycle);
    m_lengthLabel->setText(lengthStr);
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
    }
}
