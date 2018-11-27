#ifndef SIMULATEDANNEALINGALGORITHM_HPP
#define SIMULATEDANNEALINGALGORITHM_HPP

#include "algorithms/tspalgorithm.hpp"

class SimulatedAnnealingAlgorithm : public TspAlgorithm
{
public:
    virtual Result run(const AdjacencyMatrix &matrix) override;
    virtual std::string getName() const override;

private:
    void reset();

    void generateNextState(std::vector<int> &state) const;
    int computeLength(const std::vector<int> &state) const;

    const double TMIN = 0.0;
    const double TMAX = 100.0;
    const double COOLING_FACTOR = 0.01;
    const double ACCURACY = 1e-7;

    const AdjacencyMatrix *m_matrix;

};

#endif // SIMULATEDANNEALINGALGORITHM_HPP
