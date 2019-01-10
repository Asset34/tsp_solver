#ifndef SIMULATEDANNEALINGALGORITHM_HPP
#define SIMULATEDANNEALINGALGORITHM_HPP

#include "algorithms/tspalgorithm.hpp"

class SimulatedAnnealingAlgorithm : public TspAlgorithm
{
public:
    virtual std::string getName() const override;
    virtual std::vector<Parameter*> getParameters() override;

    virtual Result execute(const AdjacencyMatrix &matrix) override;

private:   

};

#endif // SIMULATEDANNEALINGALGORITHM_HPP
