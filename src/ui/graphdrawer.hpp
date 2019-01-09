#ifndef GRAPHDRAWER_HPP
#define GRAPHDRAWER_HPP

#include <QWidget>

#include <QList>
#include <QVector>

#include <adjacencymatrix.hpp>

class GraphDrawer : public QWidget
{
    Q_OBJECT

public:
    explicit GraphDrawer(QWidget *parent = nullptr);

    AdjacencyMatrix getMatrix() const;
    void setPath(const QVector<int> &numbers);

public slots:
    void generate(int count);
    void clear();
    void clearPath();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;

private:
    using Vertex = QPoint;

    Vertex generateVertex() const;
    double computeLength(const Vertex &v1, const Vertex &v2) const;

    void drawVerticies(QPainter &painter);
    void drawNumbers(QPainter &painter);
    void drawPath(QPainter &painter);

    const int VERTEX_RADIUS = 15;
    const int PADDING = 20;
    const QColor VERTEX_COLOR = Qt::yellow;
    const QColor NUMBER_COLOR = Qt::black;
    const QColor PATH_COLOR = Qt::red;

    QList<Vertex> m_vertices;
    QVector<Vertex> m_path;

};

#endif // GRAPHDRAWER_HPP
