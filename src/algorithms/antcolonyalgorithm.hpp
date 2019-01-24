#ifndef ANTCOLONYALGORITHM_HPP
#define ANTCOLONYALGORITHM_HPP

#include "tspalgorithm.hpp"

#include <parameter_list_widget/parameterized_algorithm_base/Parameters/intparameter.hpp>
#include <parameter_list_widget/parameterized_algorithm_base/Parameters/realparameter.hpp>

class AntColonyAlgorithm : public TspAlgorithm
{
public:
    AntColonyAlgorithm();

    virtual std::string getName() const override;
    virtual std::vector<Parameter*> getParameters() override;

    virtual TspResult execute(const AdjacencyMatrix &matrix) override;

private:
    IntParameter m_iterationCount;
    IntParameter m_antCount;
    RealParameter m_evaporateFactor;
    RealParameter m_alpha;
    RealParameter m_beta;

};

#endif // ANTCOLONYALGORITHM_HPP
