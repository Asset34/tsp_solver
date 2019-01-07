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

void AdjacencyMatrix::generateComplete(int min, int max)
{
    // Generate edges
    int value;
    for (int i = 0; i < m_data.size() - 1; i++) {
        for (int j = i + 1; j < m_data.size(); j++) {
                value = RandomGenerator::generateInt(min, max);

                m_data[i][j] = value;
                m_data[j][i] = value;
        }
    }

    // Disable loops
    for (int i = 0; i < m_data.size(); i++) {
        m_data[i][i] = 0;
    }
}

void AdjacencyMatrix::clear()
{
    for (std::vector<int> &column : m_data) {
        std::fill(column.begin(), column.end(), 0);
    }
}
