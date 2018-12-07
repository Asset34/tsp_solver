#ifndef NEARESTNEIGHBOURCONTROLWIDGET_HPP
#define NEARESTNEIGHBOURCONTROLWIDGET_HPP

#include "algorithmcontrolwidget.hpp"

class QFormLayout;
class QHBoxLayout;
class QSpinBox;
class QCheckBox;

class NearestNeighbourControlWidget : public AlgorithmControlWidget
{
    Q_OBJECT

public:
    explicit NearestNeighbourControlWidget(QWidget *parent = nullptr);

    virtual TspAlgorithm::Parameters getParameters() const override;

private:
    QFormLayout *m_mainLayout;
    QHBoxLayout *m_maxIterationsLayout;

    QSpinBox *m_maxIterationsSpinBox;
    QCheckBox *m_maxIterationsCheckBox;

private slots:


};


#endif // NEARESTNEIGHBOURCONTROlWIDGET_HPP
