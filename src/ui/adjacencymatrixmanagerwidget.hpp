#ifndef ADJACENCYMATRIXMANAGERWIDGET_HPP
#define ADJACENCYMATRIXMANAGERWIDGET_HPP

#include <QWidget>

#include "adjacencymatrix.hpp"

class QHBoxLayout;
class QVBoxLayout;
class QSpinBox;
class QPushButton;
class AdjacencyMatrixWidget;

class AdjacencyMatrixManagerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdjacencyMatrixManagerWidget(int size, QWidget *parent = nullptr);

    const AdjacencyMatrix &getMatrix() const;

public slots:
    void generate();
    void generateHamiltonian();
    void generateComplete();
    void clear();

private:
    const int GENERATOR_MIN = 1;
    const int GENERATOR_MAX = 100;

    QHBoxLayout *m_mainLayout;
    QVBoxLayout *m_controlLayout;

    QSpinBox *m_sizeSpinBox;

    QPushButton *m_generateButton;
    QPushButton *m_generateHamiltonianButton;
    QPushButton *m_generateCompleteButton;
    QPushButton *m_clearButton;

    AdjacencyMatrixWidget *m_matrixWidget;

};

#endif // ADJACENCYMATRIXMANAGERWIDGET_HPP
