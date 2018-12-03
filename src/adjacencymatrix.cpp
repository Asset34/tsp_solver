#include "adjacencymatrix.hpp"

#include <cmath>

#include "utills/randomgenerator.hpp"

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
    // Check edges
    for (int i = 0; i < m_data.size(); i++) {
        for (int j = 0; j < m_data.size(); j++) {
            if (m_data[i][j] != m_data[j][i]) {
                return false;
            }
        }
    }

    // Check loops
    for (int i = 0; i < m_data.size(); i++) {
        if (m_data[i][i]) {
            return false;
        }
    }

    return true;
}

bool AdjacencyMatrix::isComplete() const
{
    for (int i = 0; i < m_data.size() - 1; i++) {
        for (int j = i + 1; j < m_data.size(); j++) {
            if (m_data[i][j] != m_data[i][j] ||
                m_data[i][j] <= 0) {
                return false;
            }
        }
    }

    return true;
}

void AdjacencyMatrix::generate(int min, int max)
{
    // Generate edges
    int value;
    for (int i = 0; i < m_data.size() - 1; i++) {
        for (int j = i + 1; j < m_data.size(); j++) {
            if (RandomGenerator::generateBool()) {
                value = RandomGenerator::generateInt(min, max);

                m_data[i][j] = value;
                m_data[j][i] = value;
            }
            else {
                m_data[i][j] = 0;
                m_data[j][i] = 0;
            }
        }
    }

    // Disable loops
    for (int i = 0; i < m_data.size(); i++) {
        m_data[i][i] = 0;
    }
}

void AdjacencyMatrix::generateHamiltonian(int min, int max)
{
    clear();

    // Generate hamilton cycle
    std::vector<int> hamiltonCycle = RandomGenerator::generateSet(0, 0, m_data.size() - 1);
    hamiltonCycle.push_back(hamiltonCycle.front());

    int value;

    // Set hamilton cycle to matrix
    for (int i = 1; i < hamiltonCycle.size(); i++) {
        value = RandomGenerator::generateInt(min, max);

        m_data[hamiltonCycle[i]][hamiltonCycle[i - 1]] = value;
        m_data[hamiltonCycle[i - 1]][hamiltonCycle[i]] = value;
    }

    // Generate other
    for (int i = 0; i < m_data.size() - 1; i++) {
        for (int j = i + 1; j < m_data.size(); j++) {
            if (!m_data[i][j] && RandomGenerator::generateBool()) {
                value = RandomGenerator::generateInt(min, max);

                m_data[i][j] = value;
                m_data[j][i] = value;
            }
        }
    }
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
