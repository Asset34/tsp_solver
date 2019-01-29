#ifndef SIMULATEDANNEALINGALGORITHM_HPP
#define SIMULATEDANNEALINGALGORITHM_HPP

#include "algorithms/tspalgorithm.hpp"

#include <parameterized_algorithm_qt/core/parameters/realparameter.hpp>

class SimulatedAnnealingAlgorithm : public TspAlgorithm
{
public:
    SimulatedAnnealingAlgorithm();

    virtual std::string getName() const override;
    virtual std::vector<Parameter*> getParameters() override;

    virtual TspResult execute(const Matrix &adjacencyMatrix) override;

private:
    RealParameter m_maxt;
    RealParameter m_mint;
    RealParameter m_coolingFactor;

};

#endif // SIMULATEDANNEALINGALGORITHM_HPP
