#ifndef PARAMETERSWIDGET_HPP
#define PARAMETERSWIDGET_HPP

#include <QWidget>

#include <algorithms/tspalgorithm.hpp>

class ParametersWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParametersWidget(QWidget *parent = nullptr);
    virtual ~ParametersWidget() = default;

    virtual TspAlgorithm::Parameters getParameters() const = 0;

};

#endif // PARAMETERSWIDGET_HPP
