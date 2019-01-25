#ifndef TOUR_HPP
#define TOUR_HPP

#include <vector>
#include <string>

#include "matrix.hpp"

class Tour
{
public:
    explicit Tour(const Matrix &adjacencyMatrix);

    int operator[](int index) const;
    int &operator[](int index);

    bool operator<(const Tour &tour) const;

    int getSize() const;

    double computeLength() const;

    void addVertex(int vertex);
    void generate(int count);
    void clear();
    void close();
    void closeLast();

    void inverse(int start, int end);
    void generateInverse();

    std::string toString() const;

private:
    std::vector<int> m_vertices;
    const Matrix *m_adjacencyMatrix;

};

#endif // TOUR_HPP
