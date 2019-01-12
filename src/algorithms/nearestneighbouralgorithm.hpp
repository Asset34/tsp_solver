#ifndef NEARESTNEIGHBOURALGORITHM_HPP
#define NEARESTNEIGHBOURALGORITHM_HPP

#include "algorithms/tspalgorithm.hpp"

#include <parameter_list_widget/parameterized_algorithm_base/Parameters/intparameter.hpp>

class NearestNeighbourAlgorithm : public TspAlgorithm
{
public:
    NearestNeighbourAlgorithm();

    virtual std::string getName() const override;
    virtual std::vector<Parameter*> getParameters() override;

    virtual TspResult execute(const AdjacencyMatrix &matrix) override;

private:
    IntParameter m_start;

};

#endif // NEARESTNEIGHBOURALGORITHM_HPP
