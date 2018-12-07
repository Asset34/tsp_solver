#ifndef NEARESTNEIGHBOURALGORITHM_HPP
#define NEARESTNEIGHBOURALGORITHM_HPP

#include <set>
#include <map>

#include "algorithms/tspalgorithm.hpp"

class NearestNeighbourAlgorithm : public TspAlgorithm
{
public:
    virtual Result run(const AdjacencyMatrix &matrix, const Parameters &p) override;
    virtual std::string getName() const override;
    void clear();

private:
    bool stopCritetion() const;
    bool isVisited(int vertex) const;

    bool findNearest(int vertex);
    void addToTour(int vertex);

    int computeLength(const Tour &tour) const;

    // Processing containers
    std::set<int> m_vertexes;
    int m_nearestVertex;
    int m_iterations;
    Tour m_tour;

    // Aliases
    using Edge = std::pair<int, int>;
    using EdgeMap = std::map<int, int>;
};

#endif // NEARESTNEIGHBOURALGORITHM_HPP
