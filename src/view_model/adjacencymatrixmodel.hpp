#ifndef ADJACENCYMATRIXMODEL_HPP
#define ADJACENCYMATRIXMODEL_HPP

#include <QAbstractTableModel>

#include "../adjacencymatrix.hpp"

class AdjacencyMatrixModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit AdjacencyMatrixModel(int size, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    const AdjacencyMatrix &getMatrix() const;

    void setSize(int size);
    int getSize() const;

    void generate(int min, int max);
    void generateHamiltonian(int min, int max);
    void generateComplete(int min, int max);
    void clear();

private:
    bool checkBoundaries(const QModelIndex &index) const;

    AdjacencyMatrix m_matrix;

};

#endif // ADJACENCYMATRIXMODEL_HPP
