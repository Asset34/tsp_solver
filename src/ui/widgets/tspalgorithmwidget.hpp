#ifndef TSPALGORITHMWIDGET_HPP
#define TSPALGORITHMWIDGET_HPP

#include <QWidget>

#include <algorithms/tspalgorithm.hpp>

#include <matrix.hpp>

class QVBoxLayout;
class TspAlgorithmSelectBox;
class ParameterListWidget;
class TspResultWidget;

class TspAlgorithmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TspAlgorithmWidget(QWidget *parent = nullptr);

    TspResult execute(const Matrix &adjacencyMatrix);

private:
    QVBoxLayout *m_layout;

    TspAlgorithmSelectBox *m_algorithmSelectBox;
    ParameterListWidget *m_parameterListWidget;
    TspResultWidget *m_resultWidget;

    TspAlgorithm *m_currentAlgorithm;

private slots:
    void changeAlgorithm(TspAlgorithm *algorithm);

};


#endif // TSPALGORITHMWIDGET_HPP
