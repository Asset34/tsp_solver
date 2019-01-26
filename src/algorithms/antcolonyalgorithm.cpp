#include "antcolonyalgorithm.hpp"

#include <vector>
#include <algorithm>

#include <utills/randomgenerator.hpp>

AntColonyAlgorithm::AntColonyAlgorithm()
    : m_iterations("Iterations", 0, 1e9, 100),
      m_antCount("Ants", 0, 1e9, 10),
      m_evaporateFactor("Evaporate factor", 0.0, 1.0, 0.3),
      m_alpha("Alpha", 0.0, 1e9, 1.0),
      m_beta("Beta", 0.0, 1e9, 1.0)
{
}

std::string AntColonyAlgorithm::getName() const
{
    return "Ant Colony";
}

std::vector<Parameter*> AntColonyAlgorithm::getParameters()
{
    std::vector<Parameter*> parameters(5);
    parameters[0] = &m_iterations;
    parameters[1] = &m_antCount;
    parameters[2] = &m_evaporateFactor;
    parameters[3] = &m_alpha;
    parameters[4] = &m_beta;

    return parameters;
}

TspResult AntColonyAlgorithm::execute(const Matrix &adjacencyMatrix)
{
    // Update matrices
    m_adjacencyMatrix = adjacencyMatrix;
    m_pheromoneMatrix = Matrix(adjacencyMatrix.getSize(), 1.0);

    std::vector<Ant> ants(m_antCount, Ant(*this));
    for (int i = 0; i < m_iterations; i++) {
        // Find tours
        for (Ant &ant : ants) {
            ant.findTour();
        }

        // Update pheromone trails
        m_pheromoneMatrix.multiply(1.0 - m_evaporateFactor);
        for (Ant &ant : ants) {
            ant.updateTrail();
        }
    }

    // Find ant with best final tour
    Ant best = *std::min_element(
        ants.begin(),
        ants.end(),
        [this](const Ant &ant1, const Ant &ant2) -> bool
        {
            if (ant1.getTour() < ant2.getTour()) {
                return true;
            }
            else {
                return false;
            }
        }
    );

    return TspResult{
        .iterations = m_iterations,
        .tour = best.getTour()
    };
}
