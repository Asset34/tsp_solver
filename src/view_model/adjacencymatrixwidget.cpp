#include "adjacencymatrixwidget.hpp"

#include <QHeaderView>

AdjacencyMatrixWidget::AdjacencyMatrixWidget(int size, QWidget *parent)
    : QTableView(parent)
{
    m_model = new AdjacencyMatrixModel(size, this);

    setModel(m_model);
    horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
}

int AdjacencyMatrixWidget::getSize() const
{
    return m_model->getSize();
}

const AdjacencyMatrix &AdjacencyMatrixWidget::getMatrix() const
{
    return m_model->getMatrix();
}

void AdjacencyMatrixWidget::setSize(int size)
{
    m_model->setSize(size);
}

void AdjacencyMatrixWidget::generate(int min, int max)
{
    m_model->generate(min, max);
}

void AdjacencyMatrixWidget::clear()
{
    m_model->clear();
}
