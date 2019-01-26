#include "antcolonyalgorithm.hpp"

#include <numeric>

#include <utills/randomgenerator.hpp>

AntColonyAlgorithm::Ant::Ant(AntColonyAlgorithm &parent)
    : m_tour(parent.m_adjacencyMatrix),
      p(parent)
{
}

const Tour &AntColonyAlgorithm::Ant::getTour() const
{
    return m_tour;
}

const Tour &AntColonyAlgorithm::Ant::findTour()
{
    reset();

    int cur = generateStart();
    add(cur);

    while (!m_unvisited.empty()) {
        cur = computeNext(cur);
        add(cur);
    }

    m_tour.close();

    return m_tour;
}

void AntColonyAlgorithm::Ant::updateTrail()
{
    for (int i = 1; i < m_tour.getSize(); i++) {
        p.m_pheromoneMatrix[ m_tour[i - 1] ][ m_tour[i] ] +=
                1.0 / p.m_adjacencyMatrix[ m_tour[i - 1] ][ m_tour[i] ];
    }
}

void AntColonyAlgorithm::Ant::reset()
{
    m_unvisited.resize(p.m_adjacencyMatrix.getSize());
    std::iota(m_unvisited.begin(), m_unvisited.end(), 0);

    m_tour.clear();
}

void AntColonyAlgorithm::Ant::add(int vertex)
{
    m_unvisited.remove(vertex);
    m_tour.addVertex(vertex);
}

int AntColonyAlgorithm::Ant::generateStart()
{
    return RandomGenerator::generateInt(0, p.m_adjacencyMatrix.getSize() - 1);
}

int AntColonyAlgorithm::Ant::computeNext(int cur)
{
    double sum = 0.0;
    for (int vertex : m_unvisited) {
        sum += pow(p.m_pheromoneMatrix[cur][vertex], p.m_alpha) /
               pow(p.m_adjacencyMatrix[cur][vertex], p.m_beta);
    }

    // Compute probabilities of each vertex
    std::vector<double> chances;
    chances.reserve(m_unvisited.size());
    double chance;
    for (auto it = m_unvisited.begin(); it != m_unvisited.end(); ++it) {
        chance = pow(p.m_pheromoneMatrix[cur][*it], p.m_alpha) /
                 (pow(p.m_adjacencyMatrix[cur][*it], p.m_beta) * sum);
        chances.push_back(chance);
    }

    int index = RandomGenerator::generateRoulette(chances);

    // Convert index to vertex
    std::list<int>::iterator indexIt = m_unvisited.begin();
    std::advance(indexIt, index);
    int next = *indexIt;

    return next;
}
