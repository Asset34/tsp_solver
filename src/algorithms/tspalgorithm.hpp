#ifndef TSPALGORITHM_HPP
#define TSPALGORITHM_HPP

#include <vector>
#include <string>

#include "adjacencymatrix.hpp"

#include <parameter_list_widget/parameterized_algorithm_base/algorithm.hpp>

struct TspResult
{
    int length;
    int iterations;
    std::vector<int> path;
};

class TspAlgorithm : public Algorithm
{
public:
    virtual TspResult execute(const AdjacencyMatrix &matrix) = 0;

protected:
    int computeLength(const std::vector<int> path, const AdjacencyMatrix &matrix) const;

};

#endif // TSPALGORITHM_HPP
