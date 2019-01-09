#include "graphdrawer.hpp"

#include <QPaintEvent>
#include <QMouseEvent>

#include <QPainter>
#include <QFont>
#include <QFontMetrics>

#include <QtMath>

#include <utills/randomgenerator.hpp>

GraphDrawer::GraphDrawer(QWidget *parent)
    : QWidget(parent)
{
}

AdjacencyMatrix GraphDrawer::getMatrix() const
{
    AdjacencyMatrix matrix(m_vertices.size());

    for (int i = 0; i < m_vertices.size() - 1; i++) {
        for (int j = i + 1; j < m_vertices.size(); j++) {
            double length = computeLength(m_vertices[i], m_vertices[j]);
            matrix[i][j] = length;
            matrix[j][i] = length;
        }
    }

    return matrix;
}

void GraphDrawer::setPath(const QVector<int> &numbers)
{
    m_path.resize(numbers.size());
    for (int i = 0; i < numbers.size(); i++) {
        m_path[i] = m_vertices[numbers[i]];
    }

    update();
}

void GraphDrawer::generate(int count)
{
    clear();

    for (int i = 0; i < count; i++) {
        m_vertices.push_back(generateVertex());
    }

    setMinimumSize(size());
    update();
}

void GraphDrawer::clear()
{
    m_vertices.clear();
    m_path.clear();

    setMinimumSize(QSize(0, 0));
    update();
}

void GraphDrawer::clearPath()
{
    m_path.clear();
    update();
}

void GraphDrawer::paintEvent(QPaintEvent */*event*/)
{
    QPainter painter(this);
    painter.translate(width()/2.0, height()/2.0);

    drawPath(painter);
    drawVerticies(painter);
    drawNumbers(painter);

    painter.end();
}

void GraphDrawer::mousePressEvent(QMouseEvent *event)
{
    Vertex mappedVertex = event->pos() - Vertex(width()/2.0, height()/2.0);
    m_vertices.push_back(mappedVertex);

    setMinimumSize(size());
    update();
}

GraphDrawer::Vertex GraphDrawer::generateVertex() const
{
    int x = RandomGenerator::generateInt(
                -width()/2.0 + PADDING,
                 width()/2.0 - PADDING
                );
    int y = RandomGenerator::generateInt(
                -height()/2.0 + PADDING,
                 height()/2.0 - PADDING
                );

    return Vertex(x, y);
}

double GraphDrawer::computeLength(const Vertex &v1, const Vertex &v2) const
{
    return qSqrt(qPow(v2.x() - v1.x(), 2) + qPow(v2.y() - v1.y(), 2));
}

void GraphDrawer::drawVerticies(QPainter &painter)
{
    painter.save();

    painter.setPen(QPen(Qt::black, 2));
    painter.setBrush(QBrush(VERTEX_COLOR, Qt::SolidPattern));
    painter.setRenderHint(QPainter::Antialiasing);

    for (Vertex vertex : m_vertices) {
        painter.drawEllipse(vertex, VERTEX_RADIUS, VERTEX_RADIUS);
    }

    painter.restore();
}

void GraphDrawer::drawNumbers(QPainter &painter)
{
    painter.save();

    painter.setPen(NUMBER_COLOR);
    painter.setRenderHint(QPainter::Antialiasing);

    QFont font("Times", 10);
    QFontMetrics metrics(font);
    int dx, dy;
    QPoint pos;
    QString text;
    for (int i = 0; i < m_vertices.size(); i++) {
        text = QString::number(i);
        dx = metrics.width(text)/2.0;
        dy = -metrics.height()/4.0;
        pos = m_vertices[i] - QPoint(dx, dy);

        painter.drawText(pos, text);
    }

    painter.restore();
}

void GraphDrawer::drawPath(QPainter &painter)
{
    painter.save();

    painter.setPen(QPen(PATH_COLOR, 2));
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawLines(m_path);

    painter.restore();
}
