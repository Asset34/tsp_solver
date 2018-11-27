#ifndef SIMULATEDANNEALINGALGORITHM_HPP
#define SIMULATEDANNEALINGALGORITHM_HPP

#include "algorithms/tspalgorithm.hpp"

class SimulatedAnnealingAlgorithm : public TspAlgorithm
{
public:
    virtual Result run(const AdjacencyMatrix &matrix) override;
    virtual std::string getName() const override;

private:


};

#endif // SIMULATEDANNEALINGALGORITHM_HPP
