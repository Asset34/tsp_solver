#include "adjacencymatrix.hpp"

std::default_random_engine AdjacencyMatrix::m_randomEngine;

AdjacencyMatrix::AdjacencyMatrix(int size)
    : m_data(size, std::vector<double>(size, 0.0))
{
}

const std::vector<double> &AdjacencyMatrix::operator[](int column) const
{
    return m_data.operator[](column);
}

std::vector<double> &AdjacencyMatrix::operator[](int column)
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

void AdjacencyMatrix::generate(double min, double max)
{
    std::uniform_int_distribution<int> connectionDistr(0, 1);
    std::uniform_real_distribution<double> valueDistr(min, max);

    double value;
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
    for (std::vector<double> column : m_data) {
        std::fill(column.begin(), column.end(), 0.0);
    }
}
