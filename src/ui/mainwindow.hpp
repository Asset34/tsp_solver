#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QPushButton>

#include "ui/adjacencymatrixmanagerwidget.hpp"
#include "ui/algorithmwidget.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QHBoxLayout *m_mainlayout;
    QVBoxLayout *m_algorithmLayout;

    QPushButton *m_solveButton;

    AdjacencyMatrixManagerWidget *m_matrixWidget;
    AlgorithmWidget *m_algorithmWidget;

private slots:
    void solve();

};

#endif // MAINWINDOW_HPP
