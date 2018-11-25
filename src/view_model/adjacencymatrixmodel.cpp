#include "adjacencymatrixmodel.hpp"

AdjacencyMatrixModel::AdjacencyMatrixModel(int size, QObject *parent)
    : QAbstractTableModel(parent),
      m_matrix(size)
{
}

int AdjacencyMatrixModel::rowCount(const QModelIndex &/*parent*/) const
{
    return m_matrix.getSize();
}

int AdjacencyMatrixModel::columnCount(const QModelIndex &/*parent*/) const
{
    return m_matrix.getSize();
}

bool AdjacencyMatrixModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || !checkBoundaries(index)) {
        return false;
    }

    m_matrix[index.column()][index.row()] = value.toInt();
    emit dataChanged(index, index, {role});

    return true;
}

QVariant AdjacencyMatrixModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !checkBoundaries(index)) {
        return QVariant();
    }

    if (role == Qt::DisplayRole) {
        return m_matrix[index.column()][index.row()];
    }
    else {
        return QVariant();
    }
}

Qt::ItemFlags AdjacencyMatrixModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return Qt::ItemIsEnabled;
    }

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

const AdjacencyMatrix &AdjacencyMatrixModel::getMatrix() const
{
    return m_matrix;
}

void AdjacencyMatrixModel::setSize(int size)
{
    beginResetModel();

    m_matrix = AdjacencyMatrix(size);

    endResetModel();
}

int AdjacencyMatrixModel::getSize() const
{
    return m_matrix.getSize();
}

void AdjacencyMatrixModel::generate(int min, int max)
{
    m_matrix.generate(min, max);
}

void AdjacencyMatrixModel::clear()
{
    m_matrix.clear();
}

bool AdjacencyMatrixModel::checkBoundaries(const QModelIndex &index) const
{
    if ((index.row() >=0 && index.row() < m_matrix.getSize()) ||
        (index.column() >=0 && index.column() < m_matrix.getSize())) {
        return true;
    }

    return false;
}
