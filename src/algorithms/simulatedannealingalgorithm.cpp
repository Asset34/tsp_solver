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

TspResult SimulatedAnnealingAlgorithm::execute(const Matrix &adjacencyMatrix)
{
    // Generate initial tour
    Tour cur(adjacencyMatrix);
    cur.generate(adjacencyMatrix.getSize());
    cur.close();

    Tour next(adjacencyMatrix);
    int iterations = 0;
    double delta;
    bool action;
    double t = m_maxt;
    while (t > m_mint) {
        // Generate next tour
        next = cur;
        next.generateInverse();
        next.closeLast();

        // Attempt to update current tour
        if (next < cur) {
            cur = next;
        }
        else {
            delta = next.computeLength() - cur.computeLength();
            action = RandomGenerator::generateAction(exp(-delta/t));
            if (action) {
                cur = next;
            }
        }

        t *= m_coolingFactor;
        iterations++;
    }

    return TspResult{
        .iterations = iterations,
        .tour = cur
    };
}
