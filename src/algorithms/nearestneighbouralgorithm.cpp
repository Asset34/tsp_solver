#include "nearestneighbouralgorithm.hpp"

#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include "utills/randomgenerator.hpp"

TspAlgorithm::Result NearestNeighbourAlgorithm::run(const AdjacencyMatrix &matrix, const Parameters &p)
{
    m_matrix = &matrix;

    clear();

    // Create set of unvisited vertexes
    for (int i = 0; i < m_matrix->getSize(); i++) {
        m_vertexes.insert(i);
    }

    // Choose start vertex
    int cur = RandomGenerator::generateInt(0, m_vertexes.size() - 1);
    addToTour(cur, p);

    // Find tour
    int next;
    int iterations = 0;
    while (!m_vertexes.empty() && iterations < p.maxIterations) {
        next = findNearest(cur, p);
        if (next < 0) {
            return {false, computeLength(m_tour, p), iterations, m_tour};
        }

        addToTour(next, p);
        cur = next;

        iterations++;
    }
    m_tour.push_back(m_tour.front());

    return {true, computeLength(m_tour, p), iterations, m_tour};
}

std::string NearestNeighbourAlgorithm::getName() const
{
    return "Nearest Neighbour";
}

void NearestNeighbourAlgorithm::clear()
{
    m_vertexes.clear();
    m_tour.clear();
}

bool NearestNeighbourAlgorithm::isVisited(int vertex, const Parameters &p) const
{
    if (m_vertexes.find(vertex) == m_vertexes.end()) {
        return true;
    }

    return false;
}


int NearestNeighbourAlgorithm::findNearest(int vertex, const Parameters &p) const
{
    // Create map of edges
    EdgeMap edges;
    for (int i = 0; i < m_matrix->getSize(); i++) {
        if (!isVisited(i, p)) {
            edges.insert(Edge(i, (*m_matrix)[vertex][i]));
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

void NearestNeighbourAlgorithm::addToTour(int vertex, const Parameters &p)
{
    m_vertexes.erase(vertex);
    m_tour.push_back(vertex);
}

int NearestNeighbourAlgorithm::computeLength(const Tour &tour, const Parameters &p) const
{
    int length = 0;
    for (int i = 1; i < tour.size(); i++) {
        length += (*m_matrix)[ tour[i] ][ tour[i - 1] ];
    }

    return length;
}
