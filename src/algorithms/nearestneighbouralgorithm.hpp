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
    void reset();

    int findNearest(int curVertex) const;

    void addToCycle(int vertex);

    bool isConnected(int vertex1, int vertex2) const;
    bool isVisited(int vertex) const;

    // Processing containers
    const AdjacencyMatrix *m_matrix;
    std::set<int> m_vertexes;
    std::vector<int> m_cycle;
    int m_length;

    // Aliases
    using Edge = std::pair<int, int>;
    using EdgeMap = std::map<int, int>;
};

#endif // NEARESTNEIGHBOURALGORITHM_HPP
