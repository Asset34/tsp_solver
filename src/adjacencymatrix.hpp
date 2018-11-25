#ifndef ADJACENCYMATRIX_HPP
#define ADJACENCYMATRIX_HPP

#include <vector>
#include <random>

class AdjacencyMatrix
{
public:
    AdjacencyMatrix(int size);

    const std::vector<int> &operator[](int column) const;
    std::vector<int> &operator[](int column);

    int getSize() const;

    bool isValid() const;

    void generate(int min, int max);
    void clear();

private:
    std::vector<std::vector<int>> m_data;

    static std::default_random_engine m_randomEngine;

};

#endif // ADJACENCYMATRIX_HPP
