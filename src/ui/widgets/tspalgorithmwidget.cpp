#include "tspalgorithmwidget.hpp"

TspAlgorithmWidget::TspAlgorithmWidget(QWidget *parent)
    : AlgorithmWidget(parent)
{
}

TspResult TspAlgorithmWidget::execute(const Matrix &adjacencyMatrix)
{
    Algorithm &algorithm = getCurrentAlgorithm();
    TspAlgorithm &tspAlgorithm = static_cast<TspAlgorithm&>(algorithm);

    return tspAlgorithm.execute(adjacencyMatrix);
}
