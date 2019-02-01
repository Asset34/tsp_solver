#include "tspresultwidget.hpp"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QTextEdit>

TspResultWidget::TspResultWidget(QWidget *parent)
    : QWidget(parent)
{
    m_lengthLabel = new QLabel;
    m_iterationsLabel = new QLabel;

    m_valuesLayout = new QFormLayout;
    m_valuesLayout->setContentsMargins(0, 0, 0, 0);
    m_valuesLayout->addRow("Iterations:", m_iterationsLabel);
    m_valuesLayout->addRow("Length:", m_lengthLabel);

    m_pathTextEdit = new QTextEdit;
    m_pathTextEdit->setWordWrapMode(QTextOption::WordWrap);
    m_pathTextEdit->setReadOnly(true);

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_valuesLayout);
    m_mainLayout->addWidget(m_pathTextEdit);

    setLayout(m_mainLayout);
}

void TspResultWidget::setResult(const TspResult &result)
{
    m_iterationsLabel->setText(QString::number(result.iterations));
    m_lengthLabel->setText(QString::number(result.tour.computeLength()));
    m_pathTextEdit->setText(QString::fromStdString(result.tour.toString()));
}
