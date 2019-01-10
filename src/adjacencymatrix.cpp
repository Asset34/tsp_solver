#include "adjacencymatrix.hpp"

#include <cmath>

#include <utills/randomgenerator.hpp>

AdjacencyMatrix::AdjacencyMatrix(int size)
    : m_data(size, std::vector<int>(size, 0))
{
}

const std::vector<int> &AdjacencyMatrix::operator[](int column) const
{
    return m_data.operator[](column);
}

std::vector<int> &AdjacencyMatrix::operator[](int column)
{
    return m_data.operator[](column);
}

int AdjacencyMatrix::getSize() const
{
    return m_data.size();
}
