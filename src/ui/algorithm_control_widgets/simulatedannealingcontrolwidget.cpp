#include "simulatedannealingcontrolwidget.hpp"

#include <QFormLayout>
#include <QSpinBox>
#include <QLineEdit>

#include <QDoubleValidator>

SimulatedAnnealingControlWidget::SimulatedAnnealingControlWidget(QWidget *parent)
    : AlgorithmControlWidget (parent)
{
    // Create max iterations spin box
    m_maxIterationsSpinBox = new QSpinBox;
    m_maxIterationsSpinBox->setRange(0, 1e9);
    m_maxIterationsSpinBox->setValue(1e9);

    QDoubleValidator *tValidator = new QDoubleValidator(1e-7, 1e7, 10, this);
    QDoubleValidator *coolingFactorValidator = new QDoubleValidator(0.0, 1.0, 10, this);

    // Create line edits

    m_mintLineEdit = new QLineEdit;
    m_mintLineEdit->setValidator(tValidator);
    m_mintLineEdit->setText("1e-6");

    m_maxtLineEdit = new QLineEdit;
    m_maxtLineEdit->setValidator(tValidator);
    m_maxtLineEdit->setText("1e6");

    m_coolingFactorLineEdit = new QLineEdit;
    m_coolingFactorLineEdit->setValidator(coolingFactorValidator);
    m_coolingFactorLineEdit->setText("0.999");

    // Create layout
    m_layout = new QFormLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addRow("Max iterations:", m_maxIterationsSpinBox);
    m_layout->addRow("Min T:"         , m_mintLineEdit);
    m_layout->addRow("Max T:"         , m_maxtLineEdit);
    m_layout->addRow("Cooling factor:", m_coolingFactorLineEdit);

    // Create widget
    setLayout(m_layout);
}

TspAlgorithm::Parameters SimulatedAnnealingControlWidget::getParameters() const
{
    TspAlgorithm::Parameters p;
    p.maxIterations = m_maxIterationsSpinBox->value();
    p.mint = m_mintLineEdit->text().toDouble();
    p.maxt = m_maxtLineEdit->text().toDouble();
    p.coolingFactor = m_coolingFactorLineEdit->text().toDouble();

    return p;
}
