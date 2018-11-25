#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <QHBoxLayout>

#include "ui/adjacencymatrixmanagerwidget.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QHBoxLayout *m_mainlayout;

    AdjacencyMatrixManagerWidget *m_matrixWidget;

};

#endif // MAINWINDOW_HPP
