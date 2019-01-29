#ifndef NEARESTNEIGHBOURALGORITHM_HPP
#define NEARESTNEIGHBOURALGORITHM_HPP

#include "algorithms/tspalgorithm.hpp"

#include <parameterized_algorithm_qt/core/parameters/intparameter.hpp>

class NearestNeighbourAlgorithm : public TspAlgorithm
{
public:
    NearestNeighbourAlgorithm();

    virtual std::string getName() const override;
    virtual std::vector<Parameter*> getParameters() override;

    virtual TspResult execute(const Matrix &adjacencyMatrix) override;

private:
    IntParameter m_start;

};

#endif // NEARESTNEIGHBOURALGORITHM_HPP
