#include "simulatedannealingalgorithm.hpp"

#include <cmath>
#include <algorithm>

#include "utills/randomgenerator.hpp"

#include <QDebug>

TspAlgorithm::Result SimulatedAnnealingAlgorithm::run(const AdjacencyMatrix &matrix)
{
    m_matrix = &matrix;

    int iteratioins = 0;

    // Generate initial state
    std::vector<int> cur = RandomGenerator::generateSet(0, 0, matrix.getSize() - 1);
    cur.push_back(cur.front());
    // qDebug() << "Initial_state: " << cur << endl << endl;

    std::vector<int> next;
    int delta;
    double chance;
    double t = TMAX;
//    int t = TMAX;
    while (t > TMIN) {
        // qDebug() << "------------------------------------------";
        // qDebug() << "Temperature1: "  << t;

        next = generateNextState(cur);

        // qDebug() << "Cur: " << cur;
        // qDebug() << "Cur_length: " << computeLength(cur);
        // qDebug() << "Next: " << next;
        // qDebug() << "Next_length: " << computeLength(next);

        delta = computeLength(next) - computeLength(cur);
        // qDebug() << "Delta: " << delta;
        if (delta <= 0) {
            cur = next;
        }
        else {
            chance = exp(-delta/t);
//            chance = exp(-delta/static_cast<double>(t));
            // qDebug() << "Chance: " << chance;
            if (RandomGenerator::generateAction(chance)) {
                // qDebug() << "_ACTION_";
                cur = next;
            }
        }

        t *= COOLING_FACTOR;
//        t--;

        iteratioins++;
    }
    cur.push_back(cur.front());

    // qDebug() << "Iterations:" << iteratioins;

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

std::vector<int> SimulatedAnnealingAlgorithm::generateNextState(std::vector<int> &state) const
{
    // Generate indexes
    std::vector<int> swapIndexes = RandomGenerator::generateSet(2, 0, state.size() - 2);
    std::sort(swapIndexes.begin(), swapIndexes.end());

    // Generate new state
    std::vector<int> newState(state);
//    std::swap(newState[ swapIndexes[0] ], newState[ swapIndexes[1] ]);
    std::reverse(newState.begin() + swapIndexes[0], newState.begin() + swapIndexes[1] + 1);
    newState[newState.size() - 1] = newState.front();

    // qDebug() << "Indxes: " << swapIndexes;

    return newState;
}

int SimulatedAnnealingAlgorithm::computeLength(const std::vector<int> &state) const
{
    int length = 0;
    for (int i = 1; i < state.size(); i++) {
        length += (*m_matrix)[ state[i] ][ state[i - 1] ];
    }

    return length;
}
