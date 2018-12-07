#ifndef SIMULATEDANNEALINGCONTROLWIDGET_HPP
#define SIMULATEDANNEALINGCONTROLWIDGET_HPP

#include "algorithmcontrolwidget.hpp"

class QFormLayout;
class QSpinBox;
class QDoubleSpinBox;
class QLineEdit;

class SimulatedAnnealingControlWidget : public AlgorithmControlWidget
{
    Q_OBJECT

public:
    explicit SimulatedAnnealingControlWidget(QWidget *parent = nullptr);

    virtual TspAlgorithm::Parameters getParameters() const override;

private:
    QFormLayout *m_layout;

    QSpinBox *m_maxIterationsSpinBox;

    QLineEdit *m_mintLineEdit;
    QLineEdit *m_maxtLineEdit;
    QLineEdit *m_coolingFactorLineEdit;

};

#endif // SIMULATEDANNEALINGPACONTROLSWIDGET_HPP
