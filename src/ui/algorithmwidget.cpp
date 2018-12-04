#include "algorithmwidget.hpp"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QFrame>

#include <ui/parameterswidget.hpp>
#include <ui/nearestneighbourparameterswidget.hpp>
#include <ui/simulatedannealingparameterswidget.hpp>

#include <algorithms/nearestneighbouralgorithm.hpp>
#include <algorithms/simulatedannealingalgorithm.hpp>

AlgorithmWidget::AlgorithmWidget(QWidget *parent)
    : QWidget(parent),
      m_algorithm(nullptr)
{
    // Create algorithm combo box
    m_algorithmComboBox = new QComboBox;
    m_algorithmComboBox->addItem(QString::fromStdString(NearestNeighbourAlgorithm().getName()));
    m_algorithmComboBox->addItem(QString::fromStdString(SimulatedAnnealingAlgorithm().getName()));

    // Create separator
    m_separator = new QFrame;
    m_separator->setFrameShape(QFrame::Shape::HLine);

    // Create labels
    m_lengthLabel = new QLabel;
    m_iterationsLabel = new QLabel;

    // Create algorithm layout
    m_algorithmLayout = new QFormLayout;
    m_algorithmLayout->setContentsMargins(0, 0, 0, 0);
    m_algorithmLayout->addRow("Algorithm", m_algorithmComboBox);

    // Create result layout
    m_resultLayout = new QFormLayout;
    m_resultLayout->setContentsMargins(0, 0, 0, 0);
    m_resultLayout->addRow("Length: "    , m_lengthLabel);
    m_resultLayout->addRow("Iterations: ", m_iterationsLabel);

    // Create cycle text box
    m_cycleTextEdit = new QTextEdit;
    m_cycleTextEdit->setWordWrapMode(QTextOption::WordWrap);
    m_cycleTextEdit->setReadOnly(true);

    // Create parameters widget
    m_parametersWidget = new NearestNeighbourParametersWidget;
    m_parametersWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    // Create main layout
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_algorithmLayout);
    m_mainLayout->addWidget(m_parametersWidget);
    m_mainLayout->addWidget(m_separator);
    m_mainLayout->addLayout(m_resultLayout);
    m_mainLayout->addWidget(m_cycleTextEdit);

    // Create widget
    setLayout(m_mainLayout);

    // Create connections
    connect(
        m_algorithmComboBox,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this,
        &AlgorithmWidget::setAlgorithmParametersWidget
        );
}

AlgorithmWidget::~AlgorithmWidget()
{
    delete m_algorithm;
}

bool AlgorithmWidget::solve(const AdjacencyMatrix &matrix)
{
    resetAlgorithm();

    TspAlgorithm::Parameters p = m_parametersWidget->getParameters();
    TspAlgorithm::Result result = m_algorithm->run(matrix, p);

    // Convert results
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

void AlgorithmWidget::resetParametersWidget()
{
    m_mainLayout->removeWidget(m_parametersWidget);

    delete m_parametersWidget;

    int row = m_algorithmComboBox->currentIndex();
    switch (row) {
        case 0:
            m_parametersWidget = new NearestNeighbourParametersWidget;
        break;
        case 1:
            m_parametersWidget = new SimulatedAnnealingParametersWidget;
        break;
        default:
            m_parametersWidget = nullptr;
        break;
    }

    m_mainLayout->insertWidget(1, m_parametersWidget);
}

void AlgorithmWidget::setAlgorithmParametersWidget()
{
    resetParametersWidget();
}
