#include "resultwidget.hpp"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QTextEdit>

ResultWidget::ResultWidget(QWidget *parent)
    : QWidget(parent)
{
    m_lengthLabel = new QLabel;
    m_iterationsLabel = new QLabel;

    m_valuesLayout = new QFormLayout;
    m_valuesLayout->setContentsMargins(0, 0, 0, 0);
    m_valuesLayout->addRow("Length:", m_lengthLabel);
    m_valuesLayout->addRow("Iterations:", m_iterationsLabel);

    m_pathTextEdit = new QTextEdit;
    m_pathTextEdit->setWordWrapMode(QTextOption::WordWrap);
    m_pathTextEdit->setReadOnly(true);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_valuesLayout);
    m_mainLayout->addWidget(m_pathTextEdit);

    setLayout(m_mainLayout);
}

void ResultWidget::setResult(const TspAlgorithm::Result &result)
{
    m_lengthLabel->setText(QString::number(result.length));
    m_iterationsLabel->setText(QString::number(result.iterations));
    m_pathTextEdit->setText(buildTourString(result.tour));
}

QString ResultWidget::buildTourString(const std::vector<int> &tour) const
{
    QString tourStr;

    for (int i = 0; i < tour.size() - 1; i++) {
        tourStr.append("(" + QString::number(tour[i]) + ") => ");
    }
    tourStr.append("(" + QString::number(tour.back()) + ")");

    return tourStr;
}
