#ifndef ANTCOLONYCONTROLWIDGET_HPP
#define ANTCOLONYCONTROLWIDGET_HPP

#include "algorithmcontrolwidget.hpp"

class QFormLayout;
class QSpinBox;
class QLineEdit;

class AntColonyControlWidget : public AlgorithmControlWidget
{
    Q_OBJECT

public:
    explicit AntColonyControlWidget(QWidget *parent = nullptr);

    virtual TspAlgorithm::Parameters getParameters() const override;

private:
    QFormLayout *m_layout;

    QSpinBox *m_iterationsSpinBox;
    QSpinBox *m_antsSpinBox;

    QLineEdit *m_evapolateFactorLineEdit;
    QLineEdit *m_alphaLineEdit;
    QLineEdit *m_betaLineEdit;

};

#endif // ANTCOLONYCONTROLWIDGET_HPP
