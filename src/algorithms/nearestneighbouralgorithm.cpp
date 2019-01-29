#include "nearestneighbouralgorithm.hpp"

#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

NearestNeighbourAlgorithm::NearestNeighbourAlgorithm()
    : m_start("Start", 0, 1e9, 0)
{
}

std::string NearestNeighbourAlgorithm::getName() const
{
    return "Nearest Neighbour";
}

std::vector<Parameter*> NearestNeighbourAlgorithm::getParameters()
{
    return {
        &m_start
    };
}

TspResult NearestNeighbourAlgorithm::execute(const Matrix &adjacencyMatrix)
{
    std::list<int> unvisited(adjacencyMatrix.getSize());
    std::iota(unvisited.begin(), unvisited.end(), 0);

    Tour tour(adjacencyMatrix);
    int cur = m_start;
    while(!unvisited.empty()) {
        // Update tour
        tour.addVertex(cur);
        unvisited.remove(cur);

        // Find next vertex
        cur = *std::min_element(
            unvisited.begin(),
            unvisited.end(),
            [&adjacencyMatrix, cur](int v1, int v2) -> bool
            {
                if (adjacencyMatrix[cur][v1] < adjacencyMatrix[cur][v2]) {
                    return true;
                }
                else {
                    return false;
                }
            }
        );
    }

    tour.close();

    return TspResult{
        .iterations = adjacencyMatrix.getSize(),
        .tour = tour
    };
}
