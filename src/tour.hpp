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
    void clear();
    void close();

    std::string toString() const;

private:
    std::list<int> m_vertices;
    double m_length;

    const Matrix &m_adjacencyMatrix;

};

#endif // TOUR_HPP
