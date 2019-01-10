#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

class GraphDrawerManager;
class TspAlgorithmWidget;
class ResultWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    GraphDrawerManager *m_graphDrawerWidget;
    TspAlgorithmWidget *m_algorithmWidget;
    ResultWidget *m_resultWidget;

};

#endif // MAINWINDOW_HPP
