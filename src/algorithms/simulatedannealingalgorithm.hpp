#ifndef SIMULATEDANNEALINGALGORITHM_HPP
#define SIMULATEDANNEALINGALGORITHM_HPP

#include "algorithms/tspalgorithm.hpp"

#include <parameter_list_widget/parameterized_algorithm_base/Parameters/realparameter.hpp>

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
