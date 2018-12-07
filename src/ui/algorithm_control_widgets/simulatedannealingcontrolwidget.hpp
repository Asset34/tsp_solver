#ifndef SIMULATEDANNEALINGCONTROLWIDGET_HPP
#define SIMULATEDANNEALINGCONTROLWIDGET_HPP

#include "algorithmcontrolwidget.hpp"

class QFormLayout;
class QHBoxLayout;
class QSpinBox;
class QCheckBox;
class QDoubleSpinBox;
class QLineEdit;

class SimulatedAnnealingControlWidget : public AlgorithmControlWidget
{
    Q_OBJECT

public:
    explicit SimulatedAnnealingControlWidget(QWidget *parent = nullptr);

    virtual TspAlgorithm::Parameters getParameters() const override;

private:
    QFormLayout *m_mainLayout;
    QHBoxLayout *m_maxIterationsLayout;

    QSpinBox *m_maxIterationsSpinBox;
    QCheckBox *m_maxIterationsCheckBox;

    QLineEdit *m_mintLineEdit;
    QLineEdit *m_maxtLineEdit;
    QLineEdit *m_coolingFactorLineEdit;

};

#endif // SIMULATEDANNEALINGPACONTROLSWIDGET_HPP
