#ifndef TOUR_HPP
#define TOUR_HPP

#include <list>
#include <string>

#include "matrix.hpp"

class Tour
{
public:
    explicit Tour(const Matrix &adjacencyMatrix);

    bool operator<(const Tour &tour) const;

    std::list<int>::const_iterator getCBegin() const;
    std::list<int>::const_iterator getCEnd() const;

    int getSize() const;
    double getLength() const;

    void addVertex(int vertex);
    void generate(int count);
    void clear();
    void close();
    void closeLast();

    void inverse(int start, int end);
    void generateInverse();

    std::string toString() const;

private:
    std::list<int> m_vertices;
    double m_length;

    const Matrix *m_adjacencyMatrix;

};

#endif // TOUR_HPP
