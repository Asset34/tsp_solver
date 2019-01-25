#include "tour.hpp"

#include <algorithm>
#include <sstream>

#include <utills/randomgenerator.hpp>

Tour::Tour(const Matrix &adjacencyMatrix)
    : m_adjacencyMatrix(&adjacencyMatrix)
{
}

int Tour::operator[](int index) const
{
    return m_vertices[index];
}

int &Tour::operator[](int index)
{
    return m_vertices[index];
}

bool Tour::operator<(const Tour &tour) const
{
    return computeLength() < tour.computeLength();
}

int Tour::getSize() const
{
    return m_vertices.size();
}

double Tour::computeLength() const
{
    double length = 0.0;
    for (int i = 1; i < m_vertices.size(); i++) {
        length += (*m_adjacencyMatrix)[ m_vertices[i - 1] ][ m_vertices[i] ];
    }

    return length;
}

void Tour::addVertex(int vertex)
{
    m_vertices.push_back(vertex);
}

void Tour::generate(int count)
{
    clear();

    m_vertices =
        RandomGenerator::generateSet(
            count,
            0,
            m_adjacencyMatrix->getSize() - 1
        );
}

void Tour::clear()
{
    m_vertices.clear();
}

void Tour::close()
{
    if (!m_vertices.empty()) {
        addVertex(m_vertices.front());
    }
}

void Tour::closeLast()
{
    if (!m_vertices.empty()) {
        m_vertices.back() = m_vertices.front();
    }
}

void Tour::inverse(int start, int end)
{
    std::reverse(m_vertices.begin() + start, m_vertices.begin() + end + 1);
}

void Tour::generateInverse()
{
    // Generate indexes
    int start = RandomGenerator::generateInt(0, m_vertices.size() - 2);
    int end = RandomGenerator::generateInt(0, m_vertices.size() - 2);
    if (start > end) {
        std::swap(start, end);
    }

    inverse(start, end);
}

std::string Tour::toString() const
{
    std::ostringstream oss;

    for (int vertex : m_vertices) {
        oss << "(" << vertex << ")" << " => ";
    }

    return oss.str();
}
