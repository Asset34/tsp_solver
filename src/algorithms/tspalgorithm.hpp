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
        Tour tour;
    };

    virtual ~TspAlgorithm() = default;

    virtual Result run(const AdjacencyMatrix &matrix) = 0;
    virtual std::string getName() const = 0;

};

#endif // TSPALGORITHM_HPP
