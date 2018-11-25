#ifndef ADJACENCYMATRIXWIDGET_HPP
#define ADJACENCYMATRIXWIDGET_HPP

#include <QTableView>

#include "adjacencymatrixmodel.hpp"

class AdjacencyMatrixWidget : public QTableView
{
    Q_OBJECT

public:
    explicit AdjacencyMatrixWidget(int size, QWidget *parent = nullptr);

    int getSize() const;
    const AdjacencyMatrix &getMatrix() const;

public slots:
    void setSize(int size);
    void generate(int min, int max);
    void clear();

private:
    AdjacencyMatrixModel *m_model;

private slots:
    void adjustColumn(const QModelIndex &index);
    void adjustAll();

};

#endif // ADJACENCYMATRIXWIDGET_HPP