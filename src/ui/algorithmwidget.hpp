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

class AlgorithmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlgorithmWidget(QWidget *parent = nullptr);

public slots:
    bool solve(const AdjacencyMatrix &matrix);

private:
    QString buildCycleString(const std::vector<int> cycle) const;

    void resetAlgorithm();

    QVBoxLayout *m_mainLayout;
    QFormLayout *m_formLayout;

    QComboBox *m_algorithmComboBox;

    QLabel *m_lengthLabel;

    QTextEdit *m_cycleTextEdit;

    TspAlgorithm *m_algorithm;

};

#endif // ALGORITHMWIDGET_HPP
