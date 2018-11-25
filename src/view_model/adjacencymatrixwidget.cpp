#include "adjacencymatrixwidget.hpp"

AdjacencyMatrixWidget::AdjacencyMatrixWidget(int size, QWidget *parent)
    : QTableView(parent)
{
    m_model = new AdjacencyMatrixModel(size, this);

    setModel(m_model);

    resizeRowsToContents();
    resizeColumnsToContents();
    setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    connect(m_model, &AdjacencyMatrixModel::dataChanged, this , &AdjacencyMatrixWidget::adjustColumn);
    connect(m_model, &AdjacencyMatrixModel::modelReset, this, &AdjacencyMatrixWidget::adjustAll);
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

void AdjacencyMatrixWidget::adjustColumn(const QModelIndex &index)
{
    if (index.isValid()) {
        resizeColumnToContents(index.column());
    }
}

void AdjacencyMatrixWidget::adjustAll()
{
    resizeColumnsToContents();
}
