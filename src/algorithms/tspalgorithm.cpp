#include "tspalgorithm.hpp"

int TspAlgorithm::computeLength(const std::vector<int> path, const AdjacencyMatrix &matrix) const
{
    double length = 0.0;

    int v1, v2;
    for (int i = 1; i < path.size(); i++) {
        v1 = path[i - 1];
        v2 = path[i];
        length += matrix[v1][v2];
    }

    return length;
}
