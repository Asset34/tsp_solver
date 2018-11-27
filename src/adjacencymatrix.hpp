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

    bool isValid() const;
    bool isComplete() const;

    void generate(int min, int max);
    void generateHamiltonian(int min, int max);
    void generateComplete(int min, int max);

    void clear();

private:
    void adjustRange(int &min, int &max) const;

    std::vector<std::vector<int>> m_data;

};

#endif // ADJACENCYMATRIX_HPP
