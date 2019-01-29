#ifndef TSPALGORITHMWIDGET_HPP
#define TSPALGORITHMWIDGET_HPP

#include <algorithms/tspalgorithm.hpp>
#include <parameterized_algorithm_qt/widgets/algorithmwidget.hpp>

class TspAlgorithmWidget : public AlgorithmWidget
{
    Q_OBJECT

public:
    explicit TspAlgorithmWidget(QWidget *parent = nullptr);

    TspResult execute(const Matrix &adjacencyMatrix);

};


#endif // TSPALGORITHMWIDGET_HPP
