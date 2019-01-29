#ifndef ANTCOLONYALGORITHM_HPP
#define ANTCOLONYALGORITHM_HPP

#include <list>

#include "tspalgorithm.hpp"

#include <parameterized_algorithm_qt/core/parameters/intparameter.hpp>
#include <parameterized_algorithm_qt/core/parameters/realparameter.hpp>

class AntColonyAlgorithm : public TspAlgorithm
{
public:
    AntColonyAlgorithm();

    virtual std::string getName() const override;
    virtual std::vector<Parameter*> getParameters() override;

    virtual TspResult execute(const Matrix &adjacencyMatrix) override;

private:    
    IntParameter m_iterations;
    IntParameter m_antCount;
    RealParameter m_evaporateFactor;
    RealParameter m_alpha;
    RealParameter m_beta;

    Matrix m_adjacencyMatrix;
    Matrix m_pheromoneMatrix;

    class Ant
    {
    public:
        explicit Ant(AntColonyAlgorithm &parent);

        const Tour &getTour() const;
        const Tour &findTour();
        void updateTrail();

    private:
        void reset();

        void add(int vertex);
        int generateStart();
        int computeNext(int cur);

        std::list<int> m_unvisited;
        Tour m_tour;

        AntColonyAlgorithm &p;
    };

};

#endif // ANTCOLONYALGORITHM_HPP
