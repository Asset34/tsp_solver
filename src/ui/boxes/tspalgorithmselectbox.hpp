#ifndef TSPALGORITHMSELECTBOX_HPP
#define TSPALGORITHMSELECTBOX_HPP

#include <QComboBox>

#include <QVector>

#include <algorithms/tspalgorithm.hpp>

class TspAlgorithmSelectBox : public QComboBox
{
    Q_OBJECT

public:
    explicit TspAlgorithmSelectBox(QWidget *parent = nullptr);

    TspAlgorithm *getAlgorithm() const;

public slots:
    void changeAlgorithm(int index);

private:
    QVector<TspAlgorithm*> m_algorithms;

signals:
    void algorithmChanged(TspAlgorithm *algorithm);

};

#endif // TSPALGORITHMSELECTBOX_HPP
