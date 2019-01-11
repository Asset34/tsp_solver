#ifndef TSPALGORITHMWIDGET_HPP
#define TSPALGORITHMWIDGET_HPP

#include <QWidget>

//#include <QVector>

#include <algorithms/tspalgorithm.hpp>

#include <adjacencymatrix.hpp>

class QVBoxLayout;
class QPushButton;
class TspAlgorithmSelectBox;
class ParameterListWidget;
class TspResultWidget;

class TspAlgorithmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TspAlgorithmWidget(QWidget *parent = nullptr);

    const TspResult &getResult() const;

public slots:
    void changeAlgorithm(TspAlgorithm *algorithm);
    void execute(const AdjacencyMatrix &matrix);

private:
    QVBoxLayout *m_layout;

    TspAlgorithmSelectBox *m_algorithmSelectBox;
    ParameterListWidget *m_parameterListWidget;
    TspResultWidget *m_resultWidget;

    TspAlgorithm *m_currentAlgorithm;
    TspResult m_lastResult;

signals:
    void executed();

};


#endif // TSPALGORITHMWIDGET_HPP
