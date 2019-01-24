#include "antcolonyalgorithm.hpp"

#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <cmath>

#include <utills/randomgenerator.hpp>

#include <QDebug>

AntColonyAlgorithm::AntColonyAlgorithm()
    : m_iterationCount("Iterations", 0, 1e9, 100),
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
    parameters[0] = &m_iterationCount;
    parameters[1] = &m_antCount;
    parameters[2] = &m_evaporateFactor;
    parameters[3] = &m_alpha;
    parameters[4] = &m_beta;

    return parameters;
}

TspResult AntColonyAlgorithm::execute(const AdjacencyMatrix &matrix)
{
    // Init pheromone matrix
    std::vector<std::vector<double>> pheromoneMatrix(
                matrix.getSize(),
                std::vector<double>(matrix.getSize(), 1.0)
                );
    std::vector<std::vector<int>> paths(m_antCount, std::vector<int>(matrix.getSize() + 1));
    int curVertex;
    for (int i = 0; i < m_iterationCount; i++) {
        for (int j = 0; j < m_antCount; j++) {
            // Init list of unvisited vertices
            std::list<int> unvisited(matrix.getSize());
            std::iota(unvisited.begin(), unvisited.end(), 0);

            // Generate start vertex
            curVertex = RandomGenerator::generateInt(0, matrix.getSize() - 1);
            unvisited.remove(curVertex);

            // Update path with start vertex
            paths[j].front() = curVertex;
            paths[j].back() = curVertex;

            // Compute path
            for (int k = 1; k < matrix.getSize(); k++) {
                // Compute sum
                double sum = 0.0;
                for (int vertex : unvisited) {
                    sum += pow(pheromoneMatrix[curVertex][vertex], m_alpha) /
                           pow(matrix[curVertex][vertex], m_beta);
                }

                // Compute chances
                std::vector<double> chances;
                chances.reserve(unvisited.size());
                double chance;
                for (auto it = unvisited.begin(); it != unvisited.end(); ++it) {
                    chance = pow(pheromoneMatrix[curVertex][*it], m_alpha) / (pow(matrix[curVertex][*it], m_beta) * sum);
                    chances.push_back(chance);
                }

                // Generate next vertex
                int index = RandomGenerator::generateRoulette(chances);
                std::list<int>::iterator temp = unvisited.begin();
                std::advance(temp, index);
                curVertex = *temp;

                // Add vertex to path
                unvisited.remove(curVertex);
                paths[j][k] = curVertex;
            }
        }

        // Evaporate pheromones
        for (int j = 0; j < matrix.getSize(); j++) {
            for (int k = 0; k < matrix.getSize(); k++) {
                pheromoneMatrix[j][k] *= (1.0 - m_evaporateFactor);
            }
        }

        // Increase pheromones at paths
        int first, second;
        for (int j = 0; j < m_antCount; j++) {
            for (int k = 1; k < matrix.getSize() + 1; k++) {
                first = paths[j][k - 1];
                second = paths[j][k];
                pheromoneMatrix[first][second] += 1.0 / matrix[first][second];
            }
        }
    }

    // Find minimal path
    auto result = std::min_element(paths.begin(), paths.end(),
                                   [this, &matrix](
                                       const std::vector<int> &path1,
                                       const std::vector<int> &path2
                                   ) -> bool{
        int length1 = computeLength(path1, matrix);
        int length2 = computeLength(path2, matrix);

        if (length1 < length2) {
            return true;
        }
        else {
            return false;
        }
    });

    return {computeLength(*result, matrix), m_iterationCount, *result};
}
