#ifndef TSPALGORITHM_HPP
#define TSPALGORITHM_HPP

#include <vector>
#include <string>

#include "adjacencymatrix.hpp"

class TspAlgorithm
{
public:
    virtual ~TspAlgorithm() = default;

    struct Result
    {
        bool status;
        int length;
        std::vector<int> cycle;
    };

    virtual Result run(const AdjacencyMatrix &matrix) = 0;
    virtual std::string getName() const = 0;

protected:
    using Tour = std::vector<int>;

};

#endif // TSPALGORITHM_HPP
