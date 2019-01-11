#ifndef ANTCOLONYALGORITHM_HPP
#define ANTCOLONYALGORITHM_HPP

#include "tspalgorithm.hpp"

class AntColonyAlgorithm : public TspAlgorithm
{
public:
    virtual std::string getName() const override;
    virtual std::vector<Parameter*> getParameters() override;

    virtual TspResult execute(const AdjacencyMatrix &matrix) override;

private:

};

#endif // ANTCOLONYALGORITHM_HPP
