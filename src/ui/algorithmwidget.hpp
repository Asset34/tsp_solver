#ifndef ALGORITHMWIDGET_HPP
#define ALGORITHMWIDGET_HPP

#include <QWidget>

#include <QString>

#include "algorithms/tspalgorithm.hpp"

class QVBoxLayout;
class QFormLayout;
class QLabel;
class QComboBox;
class QTextEdit;
class QFrame;
class ParametersWidget;

class AlgorithmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlgorithmWidget(QWidget *parent = nullptr);
    virtual ~AlgorithmWidget();

public slots:
    bool solve(const AdjacencyMatrix &matrix);

private:
    QString buildCycleString(const std::vector<int> cycle) const;

    void resetAlgorithm();
    void resetParametersWidget();

    QVBoxLayout *m_mainLayout;
    QFormLayout *m_algorithmLayout;
    QFormLayout *m_resultLayout;

    QComboBox *m_algorithmComboBox;

    QLabel *m_lengthLabel;
    QLabel *m_iterationsLabel;

    QTextEdit *m_cycleTextEdit;

    QFrame *m_separator;

    ParametersWidget *m_parametersWidget;

    TspAlgorithm *m_algorithm;

private slots:
    void setAlgorithmParametersWidget();

};

#endif // ALGORITHMWIDGET_HPP
