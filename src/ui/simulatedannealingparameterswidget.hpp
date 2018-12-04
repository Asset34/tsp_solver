#ifndef SIMULATEDANNEALINGPARAMETERSWIDGET_HPP
#define SIMULATEDANNEALINGPARAMETERSWIDGET_HPP

#include "parameterswidget.hpp"

class QFormLayout;
class QSpinBox;
class QDoubleSpinBox;
class QLineEdit;

class SimulatedAnnealingParametersWidget : public ParametersWidget
{
    Q_OBJECT

public:
    explicit SimulatedAnnealingParametersWidget(QWidget *parent = nullptr);

    virtual TspAlgorithm::Parameters getParameters() const override;

private:
    QFormLayout *m_layout;

    QSpinBox *m_maxIterationsSpinBox;

    QLineEdit *m_mintLineEdit;
    QLineEdit *m_maxtLineEdit;
    QLineEdit *m_coolingFactorLineEdit;

};

#endif // SIMULATEDANNEALINGPARAMETERSWIDGET_HPP
