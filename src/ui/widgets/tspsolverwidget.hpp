#ifndef TSPSOLVERWIDGET_HPP
#define TSPSOLVERWIDGET_HPP

#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class GraphDrawerWidget;
class TspAlgorithmWidget;
class TspResultWidget;

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
    QVBoxLayout *m_panelsLayout;

    GraphDrawerWidget *m_graphDrawerWidget;
    TspAlgorithmWidget *m_algorithmWidget;
    TspResultWidget *m_resultWidget;

};

#endif // TSPSOLVERWIDGET_HPP
