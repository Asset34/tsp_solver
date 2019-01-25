#ifndef SCROLLABLEGRAPHDRAWER_HPP
#define SCROLLABLEGRAPHDRAWER_HPP

#include <QScrollArea>

#include "graphdrawer.hpp"

class ScrollableGraphDrawer : public QScrollArea
{
    Q_OBJECT

public:
    explicit ScrollableGraphDrawer(QWidget *parent = nullptr);

    Matrix getMatrix() const;
    void setTour(const Tour &tour);

public slots:
    void generate(int count);
    void clear();

private:
    GraphDrawer *m_graphDrawer;

};

#endif // SCROLLABLEGRAPHDRAWER_HPP
