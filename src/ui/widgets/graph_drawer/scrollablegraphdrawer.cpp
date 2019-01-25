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

Matrix ScrollableGraphDrawer::getMatrix() const
{
    return m_graphDrawer->getMatrix();
}

void ScrollableGraphDrawer::setTour(const Tour &tour)
{
    m_graphDrawer->setTour(tour);
}

void ScrollableGraphDrawer::generate(int count)
{
    m_graphDrawer->generate(count);
}

void ScrollableGraphDrawer::clear()
{
    m_graphDrawer->clear();
}
