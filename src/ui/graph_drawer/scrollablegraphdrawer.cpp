#include "scrollablegraphdrawer.hpp"

ScrollableGraphDrawer::ScrollableGraphDrawer(QWidget *parent)
    : QScrollArea(parent)
{
    m_graphDrawer = new GraphDrawer;

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setWidgetResizable(true);
    setWidget(m_graphDrawer);
}

AdjacencyMatrix ScrollableGraphDrawer::getMatrix() const
{
    return m_graphDrawer->getMatrix();
}

void ScrollableGraphDrawer::setPath(const QVector<int> &numbers)
{
    m_graphDrawer->setPath(numbers);
}

void ScrollableGraphDrawer::generate(int count)
{
    m_graphDrawer->generate(count);
}

void ScrollableGraphDrawer::clear()
{
    m_graphDrawer->clear();
}

void ScrollableGraphDrawer::clearPath()
{
    m_graphDrawer->clearPath();
}
