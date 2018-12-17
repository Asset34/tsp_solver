#ifndef ANTCOLONYALGORITHM_HPP
#define ANTCOLONYALGORITHM_HPP

#include "tspalgorithm.hpp"

#include <set>
#include <map>
#include <list>

class AntColonyAlgorithm : public TspAlgorithm
{
public:
    virtual Result run(const AdjacencyMatrix &matrix, const Parameters &p) override;
    virtual std::string getName() const override;
    virtual void clear() override;

private:
    using PheromoneMatrix = std::vector<std::vector<double>>;

    int findNext(
            int curVertex,
            const std::list<int> &unvisited,
            const AdjacencyMatrix &matrix,
            const PheromoneMatrix &pheromones,
            const Parameters &p
            ) const;

    int computeLength(const Tour &tour, const AdjacencyMatrix &matrix) const;

};

#endif // ANTCOLONYALGORITHM_HPP
