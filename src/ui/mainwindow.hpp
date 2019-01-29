#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class TspSolverWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
    void solve();

private:
    TspSolverWidget *m_solverWidget;

};

#endif // MAINWINDOW_HPP
