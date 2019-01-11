#ifndef RESULTWIDGET_HPP
#define RESULTWIDGET_HPP

#include <QWidget>

#include <algorithms/tspalgorithm.hpp>

class QVBoxLayout;
class QFormLayout;
class QLabel;
class QTextEdit;

class ResultWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ResultWidget(QWidget *parent = nullptr);

    void setResult(const TspResult &result);

private:
    QString buildTourString(const std::vector<int> &tour) const;

    QVBoxLayout *m_mainLayout;
    QFormLayout *m_valuesLayout;

    QLabel *m_lengthLabel;
    QLabel *m_iterationsLabel;

    QTextEdit *m_pathTextEdit;

};

#endif // RESULTWIDGET_HPP
