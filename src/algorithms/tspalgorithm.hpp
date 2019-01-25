#ifndef TSPALGORITHM_HPP
#define TSPALGORITHM_HPP

#include <vector>
#include <string>

#include "matrix.hpp"
#include "tour.hpp"

#include <parameter_list_widget/parameterized_algorithm_base/algorithm.hpp>

struct TspResult
{
    int iterations;
    Tour tour;
};

class TspAlgorithm : public Algorithm
{
public:
    virtual TspResult execute(const Matrix &adjacencyMatrix) = 0;

};

#endif // TSPALGORITHM_HPP
