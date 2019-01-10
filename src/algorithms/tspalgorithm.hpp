#ifndef TSPALGORITHM_HPP
#define TSPALGORITHM_HPP

#include <vector>
#include <string>

#include "adjacencymatrix.hpp"

#include <parameter_list_widget/parameterized_algorithm_base/algorithm.hpp>

class TspAlgorithm : public Algorithm
{
public:
    struct Result
    {
        bool status;
        int length;
        int iterations;
        std::vector<int> tour;
    };

    virtual Result execute(const AdjacencyMatrix &matrix) = 0;

};

#endif // TSPALGORITHM_HPP
