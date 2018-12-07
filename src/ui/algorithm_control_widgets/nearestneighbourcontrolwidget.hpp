#ifndef NEARESTNEIGHBOURCONTROLWIDGET_HPP
#define NEARESTNEIGHBOURCONTROLWIDGET_HPP

#include "algorithmcontrolwidget.hpp"

class QFormLayout;
class QSpinBox;

class NearestNeighbourControlWidget : public AlgorithmControlWidget
{
    Q_OBJECT

public:
    explicit NearestNeighbourControlWidget(QWidget *parent = nullptr);

    virtual TspAlgorithm::Parameters getParameters() const override;

private:
    QFormLayout *m_layout;

    QSpinBox *m_maxIterationsSpinBox;

};


#endif // NEARESTNEIGHBOURCONTROlWIDGET_HPP
