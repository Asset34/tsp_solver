#include "adjacencymatrix.hpp"

std::default_random_engine AdjacencyMatrix::m_randomEngine;

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

bool AdjacencyMatrix::isValid() const
{
    for (int i = 0; i < m_data.size(); i++) {
        for (int j = 0; j < m_data.size(); j++) {
            if (m_data[i][j] != m_data[j][i]) {
                return false;
            }
        }
    }

    return true;
}

void AdjacencyMatrix::generate(int min, int max)
{
    std::uniform_int_distribution<int> connectionDistr(0, 1);
    std::uniform_int_distribution<int> valueDistr(min, max);

    int value;
    for (int i = 0; i < m_data.size() - 1; i++) {
        for (int j = i + 1; j < m_data.size(); j++) {
            if (connectionDistr(m_randomEngine)) {
                value = valueDistr(m_randomEngine);
                m_data[i][j] = value;
                m_data[j][i] = value;
            }
        }
    }
}

void AdjacencyMatrix::clear()
{
    for (std::vector<int> column : m_data) {
        std::fill(column.begin(), column.end(), 0);
    }
}
