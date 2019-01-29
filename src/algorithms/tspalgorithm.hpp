#ifndef TSPALGORITHM_HPP
#define TSPALGORITHM_HPP

#include <vector>
#include <string>

#include "matrix.hpp"
#include "tour.hpp"

#include <parameterized_algorithm_qt/core/algorithm.hpp>

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
