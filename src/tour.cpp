#include "tour.hpp"

#include <sstream>

#include <utills/randomgenerator.hpp>

Tour::Tour(const Matrix &adjacencyMatrix)
    : m_adjacencyMatrix(&adjacencyMatrix),
      m_length(0.0)
{
}

bool Tour::operator<(const Tour &tour) const
{
    return m_length < tour.m_length;
}

std::list<int>::const_iterator Tour::getCBegin() const
{
    return m_vertices.cbegin();
}

std::list<int>::const_iterator Tour::getCEnd() const
{
    return m_vertices.cend();
}

int Tour::getSize() const
{
    return m_vertices.size();
}

double Tour::getLength() const
{
    return m_length;
}

void Tour::addVertex(int vertex)
{
    // Update length
    int last = m_vertices.back();
    m_length += (*m_adjacencyMatrix)[last][vertex];

    m_vertices.push_back(vertex);
}

void Tour::generate(int count)
{
    std::vector<int> generated = RandomGenerator::generateSet(
                                        count,
                                        0,
                                        m_adjacencyMatrix->getSize() - 1
                                     );

    std::copy(generated.begin(), generated.end(), std::back_inserter(m_vertices));
}

void Tour::clear()
{
    m_vertices.clear();
    m_length = 0.0;
}

void Tour::close()
{
    if (m_vertices.size()) {
        m_vertices.push_back(m_vertices.front());
    }
}

std::string Tour::toString() const
{
    std::ostringstream oss;

    for (int vertex : m_vertices) {
        oss << "(" << vertex << ")" << " => ";
    }

    return oss.str();
}
