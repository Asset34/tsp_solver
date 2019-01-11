#include "nearestneighbouralgorithm.hpp"

NearestNeighbourAlgorithm::NearestNeighbourAlgorithm()
    : m_iterations("Iterations", 0, 1e9, 100)
{
}

std::string NearestNeighbourAlgorithm::getName() const
{
    return "Nearest Neighbour";
}

std::vector<Parameter*> NearestNeighbourAlgorithm::getParameters()
{
    std::vector<Parameter*> parameters(1);
    parameters[0] = &m_iterations;

    return parameters;
}

TspResult NearestNeighbourAlgorithm::execute(const AdjacencyMatrix &matrix)
{
    // TODO
    return {.status = false};
}
