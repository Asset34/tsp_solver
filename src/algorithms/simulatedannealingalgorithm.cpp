#include "simulatedannealingalgorithm.hpp"

#include <cmath>

#include "utills/randomgenerator.hpp"

TspAlgorithm::Result SimulatedAnnealingAlgorithm::run(const AdjacencyMatrix &matrix)
{
    m_matrix = &matrix;

    // Generate initial state
    std::vector<int> state = RandomGenerator::generateSet(0, 0, matrix.getSize() - 1);

    std::vector<int> prev = state;
    std::vector<int> cur = state;
    int delta;
    double chance;
    double t = TMAX;
    while (t > TMIN + ACCURACY) {
        generateNextState(cur);

        delta = computeLength(cur) - computeLength(prev);
        if (delta >= 0) {
            prev = cur;
        }
        else {
            chance = exp(- delta/t);
            if (RandomGenerator::generateAction(chance)) {
                prev = cur;
            }
        }

        t *= COOLING_FACTOR;
    }
    cur.push_back(cur.front());


    return {true, computeLength(cur), cur};
}

std::string SimulatedAnnealingAlgorithm::getName() const
{
    return "Simulated annealing";
}

void SimulatedAnnealingAlgorithm::reset()
{
    // STUB
}

void SimulatedAnnealingAlgorithm::generateNextState(std::vector<int> &state) const
{
    std::vector<int> swapIndexes = RandomGenerator::generateSet(2, 0, state.size() - 1);
    std::swap(state[ swapIndexes[0] ], state[ swapIndexes[1] ]);
}

int SimulatedAnnealingAlgorithm::computeLength(const std::vector<int> &state) const
{
    int length = 0;
    for (int i = 1; i < state.size(); i++) {
        length += (*m_matrix)[ state[i] ][ state[i - 1] ];
    }

    return length;
}
