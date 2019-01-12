#include "nearestneighbouralgorithm.hpp"

#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

#include <QDebug>

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
    std::vector<Parameter*> parameters(1);
    parameters[0] = &m_start;

    return parameters;
}

TspResult NearestNeighbourAlgorithm::execute(const AdjacencyMatrix &matrix)
{
    // Init path
    std::vector<int> path(matrix.getSize() + 1);
    path[0] = m_start;
    path[matrix.getSize()] = m_start;

    // Init list of unvisited vertices
    std::list<int> unvisited(matrix.getSize());
    std::iota(unvisited.begin(), unvisited.end(), 0);
    unvisited.remove(m_start);

    std::vector<int> weights;
    int cur = m_start;
    for (int i = 1; i < matrix.getSize(); i++) {
        weights = matrix[cur];

        // Find next vertex
        cur = *std::min_element(
                  unvisited.begin(),
                  unvisited.end(),
                  [&weights](int v1, int v2) -> bool {
                      if (weights[v1] < weights[v2]) {
                          return true;
                      }
                      else {
                          return false;
                      }
                  }
        );

        // Update path and list of unvisited vertices
        path[i] = cur;
        unvisited.remove(cur);
    }

    return TspResult {
        .length = computeLength(path, matrix),
        .iterations = matrix.getSize(),
        .path = path
    };
}
