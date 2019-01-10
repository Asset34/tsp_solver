#ifndef NEARESTNEIGHBOURALGORITHM_HPP
#define NEARESTNEIGHBOURALGORITHM_HPP

#include "algorithms/tspalgorithm.hpp"

class NearestNeighbourAlgorithm : public TspAlgorithm
{
public:
    virtual std::string getName() const override;
    virtual std::vector<Parameter*> getParameters() override;

    virtual Result execute(const AdjacencyMatrix &matrix) override;

private:

};

#endif // NEARESTNEIGHBOURALGORITHM_HPP
