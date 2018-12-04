#ifndef NEARESTNEIGHBOURALGORITHM_HPP
#define NEARESTNEIGHBOURALGORITHM_HPP

#include <set>
#include <map>

#include "algorithms/tspalgorithm.hpp"

class NearestNeighbourAlgorithm : public TspAlgorithm
{
public:
    virtual Result run(const AdjacencyMatrix &matrix) override;
    virtual std::string getName() const override;

private:
    void clear();

    bool isVisited(int vertex) const;

    int findNearest(int vertex) const;
    void addToTour(int vertex);
    int computeLength(const Tour &tour) const;

    // Processing containers
    const AdjacencyMatrix *m_matrix;
    std::set<int> m_vertexes;
    Tour m_tour;

    // Aliases
    using Edge = std::pair<int, int>;
    using EdgeMap = std::map<int, int>;
};

#endif // NEARESTNEIGHBOURALGORITHM_HPP
