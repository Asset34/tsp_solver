#ifndef NEARESTNEIGHBOURPARAMETERSWIDGET_HPP
#define NEARESTNEIGHBOURPARAMETERSWIDGET_HPP

#include "parameterswidget.hpp"

class QFormLayout;
class QSpinBox;

class NearestNeighbourParametersWidget : public ParametersWidget
{
    Q_OBJECT

public:
    explicit NearestNeighbourParametersWidget(QWidget *parent = nullptr);

    virtual TspAlgorithm::Parameters getParameters() const override;

private:
    QFormLayout *m_layout;

    QSpinBox *m_maxIterationsSpinBox;

};


#endif // NEARESTNEIGHBOURPARAMETERSWIDGET_HPP
