#ifndef TSPALGORITHMWIDGET_HPP
#define TSPALGORITHMWIDGET_HPP

#include <QWidget>

#include <algorithms/tspalgorithm.hpp>

class QVBoxLayout;
class TspAlgorithmSelectBox;
class ParameterListWidget;

class TspAlgorithmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TspAlgorithmWidget(QWidget *parent = nullptr);

private:
    QVBoxLayout *m_layout;

    TspAlgorithmSelectBox *m_algorithmSelectBox;
    ParameterListWidget *m_parameterListWidget;

private slots:
    void updateParameters(TspAlgorithm *algorithm);

};



#endif // TSPALGORITHMWIDGET_HPP
