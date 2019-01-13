#include "simulatedannealingalgorithm.hpp"

#include <cmath>

#include <utills/randomgenerator.hpp>

#include <QDebug>

SimulatedAnnealingAlgorithm::SimulatedAnnealingAlgorithm()
    : m_maxt("Max T", 0.0, 1e9, 100.0),
      m_mint("Min T", 0.0, 1e9, 1.0),
      m_coolingFactor("Cooling factor", 0.0, 1.0, 0.9)
{
}

std::string SimulatedAnnealingAlgorithm::getName() const
{
    return "Simulated Annealing";
}

std::vector<Parameter*> SimulatedAnnealingAlgorithm::getParameters()
{
    std::vector<Parameter*> parameters(3);
    parameters[0] = &m_maxt;
    parameters[1] = &m_mint;
    parameters[2] = &m_coolingFactor;

    return parameters;
}

TspResult SimulatedAnnealingAlgorithm::execute(const AdjacencyMatrix &matrix)
{
    // Generate initial path
    std::vector<int> curPath = RandomGenerator::generateSet(
                                   matrix.getSize(),
                                   0,
                                   matrix.getSize() - 1
                                   );
    curPath.push_back(curPath[0]);

    std::vector<int> nextPath;
    int ind1, ind2;
    int delta;
    double chance;
    bool action;
    double t = m_maxt;
    int iteratons = 0;
    while (t > m_mint) {
        // Generate begin and end of reversing range
        ind1 = RandomGenerator::generateInt(0, matrix.getSize() - 2);
        ind2 = RandomGenerator::generateInt(0, matrix.getSize() - 2);
        if (ind1 > ind2) {
            std::swap(ind1, ind2);
        }

        // Reverse generated range of the path
        nextPath = curPath;
        std::reverse(nextPath.begin() + ind1, nextPath.begin() + ind2 + 1);
        nextPath.back() = nextPath.front();

        // Generate action
        delta = computeLength(nextPath, matrix) - computeLength(curPath, matrix);
        if (delta <= 0) {
            curPath = nextPath;
        }
        else {
            chance = exp(-delta/t);
            action = RandomGenerator::generateAction(chance);
            if (action) {
                curPath = nextPath;
            }
        }

        t *= m_coolingFactor;
        iteratons++;
    }

    return TspResult {
        .length = computeLength(curPath, matrix),
        .iterations = iteratons,
        .path = curPath
    };
}
