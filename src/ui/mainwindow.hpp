#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class QLabel;
class TspSolverWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    TspSolverWidget *m_solverWidget;

private slots:
    void indicateStart();
    void indicateFinish();

};

#endif // MAINWINDOW_HPP
