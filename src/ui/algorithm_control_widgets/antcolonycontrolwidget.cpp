#include "antcolonycontrolwidget.hpp"

#include <QFormLayout>
#include <QSpinBox>
#include <QLineEdit>

#include <QDoubleValidator>

AntColonyControlWidget::AntColonyControlWidget(QWidget *parent)
    : AlgorithmControlWidget(parent)
{
    // Create iterations spin box
    m_iterationsSpinBox = new QSpinBox;
    m_iterationsSpinBox->setRange(1, 1e9);
    m_iterationsSpinBox->setValue(10);

    // Create ants spin box
    m_antsSpinBox = new QSpinBox;
    m_antsSpinBox->setRange(1, 1e9);
    m_antsSpinBox->setValue(5);

    // Create validators
    QDoubleValidator *validator = new QDoubleValidator(0.0, 1.0, 10, this);

    // Create evapolate factor
    m_evapolateFactorLineEdit = new QLineEdit("0,1");
    m_evapolateFactorLineEdit->setValidator(validator);

    // Create alpha line edit
    m_alphaLineEdit = new QLineEdit("1");
    m_alphaLineEdit->setValidator(validator);

    // Create beta line edit
    m_betaLineEdit = new QLineEdit("1");
    m_betaLineEdit->setValidator(validator);

    // Create layout
    m_layout = new QFormLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addRow("Iterations:"      , m_iterationsSpinBox);
    m_layout->addRow("Ants:"            , m_antsSpinBox);
    m_layout->addRow("Evapolate factor:", m_evapolateFactorLineEdit);
    m_layout->addRow("Alpha:"           , m_alphaLineEdit);
    m_layout->addRow("Beta:"            , m_betaLineEdit);

    // Create widget
    setLayout(m_layout);
}

TspAlgorithm::Parameters AntColonyControlWidget::getParameters() const
{
    TspAlgorithm::Parameters p;
    p.maxIterations = m_iterationsSpinBox->value();
    p.antCount = m_antsSpinBox->value();
    p.evaporateFactor = m_evapolateFactorLineEdit->text().toDouble();
    p.alpha = m_alphaLineEdit->text().toDouble();
    p.beta = m_betaLineEdit->text().toDouble();

    return p;
}
