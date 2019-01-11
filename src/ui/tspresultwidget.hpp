#ifndef TSPRESULTWIDGET_HPP
#define TSPRESULTWIDGET_HPP

#include <QWidget>

#include <algorithms/tspalgorithm.hpp>

class QVBoxLayout;
class QFormLayout;
class QLabel;
class QTextEdit;

class TspResultWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TspResultWidget(QWidget *parent = nullptr);

    void setResult(const TspResult &result);

private:
    QString buildTourString(const std::vector<int> &tour) const;

    QVBoxLayout *m_mainLayout;
    QFormLayout *m_valuesLayout;

    QLabel *m_lengthLabel;
    QLabel *m_iterationsLabel;

    QTextEdit *m_pathTextEdit;

};

#endif // TSPRESULTWIDGET_HPP
