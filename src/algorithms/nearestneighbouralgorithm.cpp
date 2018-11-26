#include "nearestneighbouralgorithm.hpp"

#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include "utills/randomgenerator.hpp"

TspAlgorithm::Result NearestNeighbourAlgorithm::run(const AdjacencyMatrix &matrix)
{
    m_matrix = &matrix;

    reset();

    // Create set of unvisited vertexes
    for (int i = 0; i < m_matrix->getSize(); i++) {
        m_vertexes.insert(i);
    }

    // Choose start vertex
    int start = RandomGenerator::generateInt(0, m_vertexes.size() - 1);
    addToCycle(start);

    // Find hamilton cycle
    int cur = start;
    int next;
    while (!m_vertexes.empty()) {
        next = findNearest(cur);
        if (next < 0) {
            return {false, m_length, m_cycle};
        }

        m_length += (*m_matrix)[cur][next];

        addToCycle(next);
        cur = next;
    }

    // Finish hamiltom cycle
    if (!isConnected(cur, start)) {
        return {false, m_length, m_cycle};
    }

    m_cycle.push_back(start);

    return {true, m_length, m_cycle};
}

std::string NearestNeighbourAlgorithm::getName() const
{
    return "Nearest Neighbour";
}

void NearestNeighbourAlgorithm::reset()
{
    m_vertexes.clear();
    m_cycle.clear();
    m_length = 0;
}

int NearestNeighbourAlgorithm::findNearest(int curVertex) const
{
    // Create map of edges
    EdgeMap edges;
    for (int i = 0; i < m_matrix->getSize(); i++) {
        if (isConnected(curVertex, i) && !isVisited(i)) {
            edges.insert(Edge(i, (*m_matrix)[curVertex][i]));
        }
    }

    if (edges.empty()) {
        return -1;
    }

    // Find edge with minimum weight
    Edge minEdge = *std::min_element(
                edges.begin(),
                edges.end(),
                [](Edge e1, Edge e2) -> bool {
            return e1.second < e2.second;
    });

    return minEdge.first;
}

void NearestNeighbourAlgorithm::addToCycle(int vertex)
{
    m_vertexes.erase(vertex);
    m_cycle.push_back(vertex);
}

bool NearestNeighbourAlgorithm::isConnected(int vertex1, int vertex2) const
{
    if ((*m_matrix)[vertex1][vertex2] > 0) {
        return true;
    }

    return false;
}

bool NearestNeighbourAlgorithm::isVisited(int vertex) const
{
    if (m_vertexes.find(vertex) == m_vertexes.end()) {
        return true;
    }

    return false;
}
