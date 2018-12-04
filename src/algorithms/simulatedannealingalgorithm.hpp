#ifndef SIMULATEDANNEALINGALGORITHM_HPP
#define SIMULATEDANNEALINGALGORITHM_HPP

#include "algorithms/tspalgorithm.hpp"

class SimulatedAnnealingAlgorithm : public TspAlgorithm
{
public:
    virtual Result run(const AdjacencyMatrix &matrix, const Parameters &p) override;
    virtual std::string getName() const override;

private:
    Tour tourGenerationFunc(const Tour &tour, const Parameters &p) const;
    int tourLengthFunc(const Tour &tour, const Parameters &p) const;
    double temperatureFunc(double t, const Parameters &p) const;

    const AdjacencyMatrix *m_matrix;

};

#endif // SIMULATEDANNEALINGALGORITHM_HPP
