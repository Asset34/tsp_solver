#ifndef GRAPHDRAWERMANAGER_HPP
#define GRAPHDRAWERMANAGER_HPP

#include <QWidget>

#include <adjacencymatrix.hpp>

class QVBoxLayout;
class QHBoxLayout;
class QScrollArea;
class QSpinBox;
class QPushButton;
class ScrollableGraphDrawer;

class GraphDrawerManager : public QWidget
{
    Q_OBJECT

public:
    explicit GraphDrawerManager(QWidget *parent = nullptr);

    AdjacencyMatrix getMatrix() const;
    void setPath(const QVector<int> &numbers);

private:
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_controlLayout;

    ScrollableGraphDrawer *m_drawer;

    QSpinBox *m_sizeSpinBox;

    QPushButton *m_generateButton;
    QPushButton *m_clearButton;

private slots:
    void generate();
    void clear();

};

#endif // GRAPHDRAWERMANAGER_HPP
