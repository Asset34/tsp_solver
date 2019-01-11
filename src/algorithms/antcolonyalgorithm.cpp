#include "antcolonyalgorithm.hpp"

std::string AntColonyAlgorithm::getName() const
{
    return "Ant Colony";
}

std::vector<Parameter*> AntColonyAlgorithm::getParameters()
{
    // TODO
    return {};
}

TspResult AntColonyAlgorithm::execute(const AdjacencyMatrix &matrix)
{
    // TODO
    return {.status = false};
}
