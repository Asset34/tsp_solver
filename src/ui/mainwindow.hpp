#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <QString>

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
    void indicateSolverStatus(QString status);

};

#endif // MAINWINDOW_HPP
