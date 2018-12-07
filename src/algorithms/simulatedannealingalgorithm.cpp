#include "simulatedannealingalgorithm.hpp"

#include <cmath>
#include <algorithm>

#include "utills/randomgenerator.hpp"

TspAlgorithm::Result SimulatedAnnealingAlgorithm::run(const AdjacencyMatrix &matrix, const Parameters &p)
{
    clear();

    m_matrix = &matrix;
    m_parameters = p;

    // Generate initial tour
    Tour cur = RandomGenerator::generateSet(0, 0, matrix.getSize() - 1);
    cur.push_back(cur.front());

    Tour next;
    int delta;
    double chance;
    double t = p.maxt;
    while (!stopCriterion(t)) {
        next = tourGenerationFunc(cur);

        delta = tourLengthFunc(next) - tourLengthFunc(cur);
        if (delta <= 0) {
            cur = next;
        }
        else {
            chance = exp(-delta/t);
            if (RandomGenerator::generateAction(chance)) {
                cur = next;
            }
        }

        t = temperatureFunc(t);

        m_iterations++;
    }

    return {true, tourLengthFunc(cur), m_iterations, cur};
}

std::string SimulatedAnnealingAlgorithm::getName() const
{
    return "Simulated annealing";
}

void SimulatedAnnealingAlgorithm::clear()
{
    m_iterations = 0;
}

TspAlgorithm::Tour SimulatedAnnealingAlgorithm::tourGenerationFunc(const Tour &tour) const
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

int SimulatedAnnealingAlgorithm::tourLengthFunc(const Tour &tour) const
{
    int length = 0;
    for (int i = 1; i < tour.size(); i++) {
        length += (*m_matrix)[ tour[i] ][ tour[i - 1] ];
    }

    return length;
}

double SimulatedAnnealingAlgorithm::temperatureFunc(double t) const
{
    return t * m_parameters.coolingFactor;
}

bool SimulatedAnnealingAlgorithm::stopCriterion(double t) const
{
    return t <= m_parameters.mint ||
           (m_parameters.maxIterationsFlag &&
           m_iterations >= m_parameters.maxIterations);
}
