#ifndef ANTCOLONYALGORITHM_HPP
#define ANTCOLONYALGORITHM_HPP

#include "tspalgorithm.hpp"

class AntColonyAlgorithm : public TspAlgorithm
{
public:
    virtual Result run(const AdjacencyMatrix &matrix, const Parameters &p) = 0;
    virtual std::string getName() const = 0;
    virtual void clear() = 0;

private:

};

#endif // ANTCOLONYALGORITHM_HPP
