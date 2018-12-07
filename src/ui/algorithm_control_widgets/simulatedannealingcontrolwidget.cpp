#include "simulatedannealingcontrolwidget.hpp"

#include <QFormLayout>
#include <QHBoxLayout>

#include <QSpinBox>
#include <QCheckBox>
#include <QLineEdit>

#include <QDoubleValidator>

SimulatedAnnealingControlWidget::SimulatedAnnealingControlWidget(QWidget *parent)
    : AlgorithmControlWidget (parent)
{
    // Create max iterations spin box
    m_maxIterationsSpinBox = new QSpinBox;
    m_maxIterationsSpinBox->setRange(0, 1e9);
    m_maxIterationsSpinBox->setValue(0);
    m_maxIterationsSpinBox->setEnabled(false);

    // Create max iterations check box
    m_maxIterationsCheckBox = new QCheckBox;
    m_maxIterationsCheckBox->setChecked(false);

    // Create max iterations layout
    m_maxIterationsLayout = new QHBoxLayout;
    m_maxIterationsLayout->setContentsMargins(0, 0, 0, 0);
    m_maxIterationsLayout->addWidget(m_maxIterationsCheckBox);
    m_maxIterationsLayout->addWidget(m_maxIterationsSpinBox);

    // Create max iterations widget
    QWidget *maxIterationsWidget = new QWidget;
    maxIterationsWidget->setLayout(m_maxIterationsLayout);

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
    m_mainLayout = new QFormLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addRow("Max iterations:", maxIterationsWidget);
    m_mainLayout->addRow("Min T:"         , m_mintLineEdit);
    m_mainLayout->addRow("Max T:"         , m_maxtLineEdit);
    m_mainLayout->addRow("Cooling factor:", m_coolingFactorLineEdit);

    // Create widget
    setLayout(m_mainLayout);

    // Create connections
    connect(m_maxIterationsCheckBox, &QCheckBox::clicked,
            [this](bool checked){
        m_maxIterationsSpinBox->setEnabled(checked);
    });
}

TspAlgorithm::Parameters SimulatedAnnealingControlWidget::getParameters() const
{
    TspAlgorithm::Parameters p;
    p.maxIterations = m_maxIterationsSpinBox->value();
    p.maxIterationsFlag = m_maxIterationsCheckBox->isChecked();
    p.mint = m_mintLineEdit->text().toDouble();
    p.maxt = m_maxtLineEdit->text().toDouble();
    p.coolingFactor = m_coolingFactorLineEdit->text().toDouble();

    return p;
}
