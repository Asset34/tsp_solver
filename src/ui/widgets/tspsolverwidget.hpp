#ifndef TSPSOLVERWIDGET_HPP
#define TSPSOLVERWIDGET_HPP

#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QPushButton;
class GraphDrawerWidget;
class TspAlgorithmWidget;

class TspSolverWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TspSolverWidget(QWidget *parent = nullptr);

public slots:
    void generate();
    void clear();
    void solve();

private:
    QHBoxLayout *m_mainlayout;
    QVBoxLayout *m_algorithmLayout;

    QPushButton *m_solveButton;

    GraphDrawerWidget *m_graphDrawerWidget;
    TspAlgorithmWidget *m_algorithmWidget;

};

#endif // TSPSOLVERWIDGET_HPP
