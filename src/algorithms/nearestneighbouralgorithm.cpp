#include "nearestneighbouralgorithm.hpp"

#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include "utills/randomgenerator.hpp"

TspAlgorithm::Result NearestNeighbourAlgorithm::run(const AdjacencyMatrix &matrix, const Parameters &p)
{
    clear();

    m_matrix = &matrix;
    m_parameters = p;

    // Create set of unvisited vertexes
    for (int i = 0; i < m_matrix->getSize(); i++) {
        m_vertexes.insert(i);
    }

    // Choose start vertex
    int cur = RandomGenerator::generateInt(0, m_vertexes.size() - 1);
    addToTour(cur);

    // Find tour
    bool isNearestExist;
    while (!stopCritetion()) {
        isNearestExist = findNearest(cur);

        if (!isNearestExist) {
            return {false, computeLength(m_tour), m_iterations, m_tour};
        }

        addToTour(m_nearestVertex);
        cur = m_nearestVertex;

        m_iterations++;
    }
    m_tour.push_back(m_tour.front());

    return {true, computeLength(m_tour), m_iterations, m_tour};
}

std::string NearestNeighbourAlgorithm::getName() const
{
    return "Nearest Neighbour";
}

void NearestNeighbourAlgorithm::clear()
{
    m_vertexes.clear();
    m_tour.clear();
    m_iterations = 0;
}

bool NearestNeighbourAlgorithm::stopCritetion() const
{
    return m_vertexes.empty() ||
           (m_parameters.maxIterationsFlag &&
            m_iterations >= m_parameters.maxIterations);
}

bool NearestNeighbourAlgorithm::isVisited(int vertex) const
{
    if (m_vertexes.find(vertex) == m_vertexes.end()) {
        return true;
    }

    return false;
}

bool NearestNeighbourAlgorithm::findNearest(int vertex)
{
    // Create map of edges
    EdgeMap edges;
    for (int i = 0; i < m_matrix->getSize(); i++) {
        if (!isVisited(i)) {
            edges.insert(Edge(i, (*m_matrix)[vertex][i]));
        }
    }

    if (edges.empty()) {
        return false;
    }

    // Find edge with minimum weight
    Edge minEdge = *std::min_element(
                edges.begin(),
                edges.end(),
                [](Edge e1, Edge e2) -> bool {
            return e1.second < e2.second;
    });

    m_nearestVertex = minEdge.first;

    return true;
}

void NearestNeighbourAlgorithm::addToTour(int vertex)
{
    m_vertexes.erase(vertex);
    m_tour.push_back(vertex);
}

int NearestNeighbourAlgorithm::computeLength(const Tour &tour) const
{
    int length = 0;
    for (int i = 1; i < tour.size(); i++) {
        length += (*m_matrix)[ tour[i] ][ tour[i - 1] ];
    }

    return length;
}
