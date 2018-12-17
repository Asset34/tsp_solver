#ifndef TSPALGORITHM_HPP
#define TSPALGORITHM_HPP

#include <vector>
#include <string>

#include "adjacencymatrix.hpp"

class TspAlgorithm
{
public:
    using Tour = std::vector<int>;

    struct Result
    {
        bool status;
        int length;
        int iterations;
        Tour tour;
    };

    struct Parameters
    {
        // General parameters
        int maxIterations;
        bool maxIterationsFlag;

        // Simulated annealing algorithm parameters
        double mint;
        double maxt;
        double coolingFactor;

        // Ant colony algorithm parameters
        int antCount;
        double alpha;
        double beta;
        double evaporateFactor;
    };

    virtual ~TspAlgorithm() = default;

    virtual Result run(const AdjacencyMatrix &matrix, const Parameters &p) = 0;
    virtual std::string getName() const = 0;
    virtual void clear() = 0;

protected:
    const AdjacencyMatrix *m_matrix;
    Parameters m_parameters;

};

#endif // TSPALGORITHM_HPP
