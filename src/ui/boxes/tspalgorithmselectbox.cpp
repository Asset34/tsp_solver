#include "tspalgorithmselectbox.hpp"

#include <algorithms/nearestneighbouralgorithm.hpp>
#include <algorithms/simulatedannealingalgorithm.hpp>
#include <algorithms/antcolonyalgorithm.hpp>

TspAlgorithmSelectBox::TspAlgorithmSelectBox(QWidget *parent)
    : QComboBox(parent)
{
    m_algorithms.resize(3);
    m_algorithms[0] = new NearestNeighbourAlgorithm;
    m_algorithms[1] = new SimulatedAnnealingAlgorithm;
    m_algorithms[2] = new AntColonyAlgorithm;

    for (TspAlgorithm *algorithm : m_algorithms) {
        addItem(QString::fromStdString(algorithm->getName()));
    }

    connect(
        this,
        static_cast<void (TspAlgorithmSelectBox::*)(int)>(&TspAlgorithmSelectBox::currentIndexChanged),
        this,
        &TspAlgorithmSelectBox::changeAlgorithm
        );
}

TspAlgorithm *TspAlgorithmSelectBox::getAlgorithm() const
{
    return m_algorithms[currentIndex()];
}

void TspAlgorithmSelectBox::changeAlgorithm(int index)
{
    emit algorithmChanged(m_algorithms[index]);
}
