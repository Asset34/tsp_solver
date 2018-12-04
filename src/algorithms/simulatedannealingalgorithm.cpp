#include "simulatedannealingalgorithm.hpp"

#include <cmath>
#include <algorithm>

#include "utills/randomgenerator.hpp"

#include <QDebug>

TspAlgorithm::Result SimulatedAnnealingAlgorithm::run(const AdjacencyMatrix &matrix, const Parameters &p)
{
    m_matrix = &matrix;

    // Generate initial tour
    Tour cur = RandomGenerator::generateSet(0, 0, matrix.getSize() - 1);
    cur.push_back(cur.front());

    Tour next;
    int delta;
    double chance;
    int iterations = 0;
    double t = p.maxt;
    while (t > p.mint && iterations < p.maxIterations) {
        next = tourGenerationFunc(cur, p);

        delta = tourLengthFunc(next, p) - tourLengthFunc(cur, p);
        if (delta <= 0) {
            cur = next;
        }
        else {
            chance = exp(-delta/t);
            if (RandomGenerator::generateAction(chance)) {
                cur = next;
            }
        }

        t = temperatureFunc(t, p);

        iterations++;
    }

    return {true, tourLengthFunc(cur, p), iterations, cur};
}

std::string SimulatedAnnealingAlgorithm::getName() const
{
    return "Simulated annealing";
}

TspAlgorithm::Tour SimulatedAnnealingAlgorithm::tourGenerationFunc(const Tour &tour, const Parameters &p) const
{
    // Generate indexes
    std::vector<int> indexes = RandomGenerator::generateSet(2, 0, tour.size() - 2);
    std::sort(indexes.begin(), indexes.end());

    // Generate new state
    std::vector<int> newTour(tour);
    std::reverse(newTour.begin() + indexes[0], newTour.begin() + indexes[1] + 1);
    newTour.back() = newTour.front();

    return newTour;
}

int SimulatedAnnealingAlgorithm::tourLengthFunc(const Tour &tour, const Parameters &p) const
{
    int length = 0;
    for (int i = 1; i < tour.size(); i++) {
        length += (*m_matrix)[ tour[i] ][ tour[i - 1] ];
    }

    return length;
}

double SimulatedAnnealingAlgorithm::temperatureFunc(double t, const Parameters &p) const
{
    return t * p.coolingFactor;
}
