#ifndef TSPALGORITHMWIDGET_HPP
#define TSPALGORITHMWIDGET_HPP

#include <QWidget>

#include <matrix.hpp>
#include <algorithms/tspalgorithm.hpp>

class QVBoxLayout;
class AlgorithmWidget;
class TspResultWidget;

class TspAlgorithmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TspAlgorithmWidget(QWidget *parent = nullptr);

    TspResult execute(const Matrix &adjacencyMatrix);

private:
    QVBoxLayout *m_layout;

    AlgorithmWidget *m_algorithmWidget;
    TspResultWidget *m_resultWidget;

};


#endif // TSPALGORITHMWIDGET_HPP
