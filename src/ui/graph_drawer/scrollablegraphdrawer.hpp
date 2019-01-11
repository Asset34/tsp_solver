#ifndef SCROLLABLEGRAPHDRAWER_HPP
#define SCROLLABLEGRAPHDRAWER_HPP

#include <QScrollArea>

#include "graphdrawer.hpp"

class ScrollableGraphDrawer : public QScrollArea
{
    Q_OBJECT

public:
    explicit ScrollableGraphDrawer(QWidget *parent = nullptr);

    AdjacencyMatrix getMatrix() const;
    void setPath(const QVector<int> &numbers);

public slots:
    void generate(int count);
    void clear();
    void clearPath();

private:
    GraphDrawer *m_graphDrawer;

};

#endif // SCROLLABLEGRAPHDRAWER_HPP
