#include "antcolonyalgorithm.hpp"

#include <list>
#include <algorithm>
#include <cmath>

#include <utills/randomgenerator.hpp>

#include <QDebug>

TspAlgorithm::Result AntColonyAlgorithm::run(
        const AdjacencyMatrix &matrix,
        const TspAlgorithm::Parameters &p
        )
{
    // Define general parameters
    int vertexCount = matrix.getSize();

    // Init pheromone matrix
    std::vector<std::vector<double>> pheromones(vertexCount, std::vector<double>(vertexCount, 1.0));

    std::vector<Tour> tours(p.antCount);
    std::list<int> unvisited;
    std::vector<int> tour(vertexCount + 1);
    int curVertex;
    for (int i = 0; i < p.maxIterations; i++) {
        for (int j = 0; j < p.antCount; j++) {
            // Generate start vertex
            curVertex = RandomGenerator::generateInt(0, vertexCount);

            // Init list of unvisited vertexes
            unvisited.resize(matrix.getSize());
            std::iota(unvisited.begin(), unvisited.end(), 0);
            unvisited.remove(curVertex);

            // Init tour with start vertex
            tour.resize(vertexCount);
            tour[0] = curVertex;
            tour[vertexCount] = curVertex;

            // Compute tour
            for (int v = 1; v < vertexCount; v++) {
                curVertex = findNext(curVertex, unvisited, matrix, pheromones, p);

                unvisited.remove(curVertex);
                tour[v] = curVertex;
            }

            tours[j] = tour;
        }

        // Evaporate pheromones
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                pheromones[i][j] *= (1.0 - p.evaporateFactor);
            }
        }

        // Increase pheromones at tours
        int first, second;
        for (Tour tour : tours) {
            for (int i = 1; i < tour.size(); i++) {
                first = tour[i - 1];
                second = tour[i];
                pheromones[first][second] += 1.0 / matrix[first][second];
            }
        }
    }

    // Find minimal
    auto result = std::min_element(tours.begin(), tours.end(),
                     [this, &matrix](const Tour &t1, const Tour &t2) -> bool{
        int length1 = computeLength(t1, matrix);
        int length2 = computeLength(t2, matrix);

        if (length1 < length2) {
            return true;
        }
        else {
            return false;
        }
    });


    return {true, computeLength(*result, matrix), p.maxIterations, *result};
}

std::string AntColonyAlgorithm::getName() const
{
    return "Ant colony";
}

void AntColonyAlgorithm::clear()
{
    // STUB
}

int AntColonyAlgorithm::findNext(int curVertex,
        const std::list<int> &unvisited,
        const AdjacencyMatrix &matrix,
        const AntColonyAlgorithm::PheromoneMatrix &pheromones,
        const Parameters &p
        ) const
{
    // Compute sum
    double sum = 0.0;
    for (int v : unvisited) {
        sum += pow(matrix[curVertex][v], p.alpha) / pow(pheromones[curVertex][v], p.beta);
    }

    // Compute chance of each vertex
    std::vector<double> chances(unvisited.size());
    for (int v = 0; v < unvisited.size(); v++) {
        chances[v] = pheromones[curVertex][v] / (matrix[curVertex][v] * sum);
    }

    // Generate next vertex
    return RandomGenerator::generateRoulette(chances);
}

int AntColonyAlgorithm::computeLength(const Tour &tour, const AdjacencyMatrix &matrix) const
{
    int length = 0;
    for (int i = 1; i < tour.size(); i++) {
        length += matrix[ tour[i - 1] ][ tour[i] ];
    }

    return length;
}
