#ifndef GRAPHDRAWERWIDGET_HPP
#define GRAPHDRAWERWIDGET_HPP

#include <QWidget>

#include <adjacencymatrix.hpp>

class QVBoxLayout;
class QHBoxLayout;
class QScrollArea;
class QSpinBox;
class QPushButton;
class ScrollableGraphDrawer;

class GraphDrawerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphDrawerWidget(QWidget *parent = nullptr);

    AdjacencyMatrix getMatrix() const;
    void setPath(const QVector<int> &numbers);

public slots:
    void generate();
    void clear();
    void clearPath();

private:
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_controlLayout;

    ScrollableGraphDrawer *m_drawer;

    QSpinBox *m_sizeSpinBox;

    QPushButton *m_generateButton;
    QPushButton *m_clearButton;

};

#endif // GRAPHDRAWERWIDGET_HPP
