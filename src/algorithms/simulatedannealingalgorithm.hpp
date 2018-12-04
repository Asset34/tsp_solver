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

    std::vector<int> generateNextState(std::vector<int> &state) const;
    int computeLength(const std::vector<int> &state) const;

    const double TMIN = 1e-4;
    const double TMAX = 1000000.0;
//    const int TMIN = 0;
//    const int TMAX = 100;
    const double COOLING_FACTOR = 0.9999;

    const AdjacencyMatrix *m_matrix;

};

#endif // SIMULATEDANNEALINGALGORITHM_HPP
