#ifndef SIMULATEDANNEALINGALGORITHM_HPP
#define SIMULATEDANNEALINGALGORITHM_HPP

#include "algorithms/tspalgorithm.hpp"

class SimulatedAnnealingAlgorithm : public TspAlgorithm
{
public:
    virtual Result run(const AdjacencyMatrix &matrix, const Parameters &p) override;
    virtual std::string getName() const override;
    void clear();

private:   
    Tour tourGenerationFunc(const Tour &tour) const;
    int tourLengthFunc(const Tour &tour) const;
    double temperatureFunc(double t) const;

    bool stopCriterion(double t) const;

    int m_iterations;

};

#endif // SIMULATEDANNEALINGALGORITHM_HPP
