#ifndef ALGORITHMCONTROLWIDGET_HPP
#define ALGORITHMCONTROLWIDGET_HPP

#include <QWidget>

#include <algorithms/tspalgorithm.hpp>

class AlgorithmControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlgorithmControlWidget(QWidget *parent = nullptr);
    virtual ~AlgorithmControlWidget() = default;

    virtual TspAlgorithm::Parameters getParameters() const = 0;

};

#endif // ALGORITHMCONTROLWIDGET_HPP
