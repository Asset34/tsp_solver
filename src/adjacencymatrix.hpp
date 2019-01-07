#ifndef ADJACENCYMATRIX_HPP
#define ADJACENCYMATRIX_HPP

#include <vector>

class AdjacencyMatrix
{
public:
    AdjacencyMatrix(int size);

    const std::vector<int> &operator[](int column) const;
    std::vector<int> &operator[](int column);

    int getSize() const;

    void generateComplete(int min, int max);
    void clear();

private:
    std::vector<std::vector<int>> m_data;

};

#endif // ADJACENCYMATRIX_HPP
