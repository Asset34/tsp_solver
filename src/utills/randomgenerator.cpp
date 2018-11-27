#include "randomgenerator.hpp"

#include <algorithm>
#include <chrono>

//std::default_random_engine RandomGenerator::m_engine(
//        std::chrono::system_clock::now().time_since_epoch().count()
//        );

std::default_random_engine RandomGenerator::m_engine;
std::uniform_int_distribution<int> RandomGenerator::m_boolDistr(0, 1);

bool RandomGenerator::generateBool()
{
    return m_boolDistr(m_engine);
}

int RandomGenerator::generateInt(int min, int max)
{
    return std::uniform_int_distribution<int>{min, max}(m_engine);
}

std::vector<int> RandomGenerator::generateSet(int count, int min, int max)
{
    // Create range vector
    std::vector<int> values(max - min + 1);
    for (int i = 0; i < values.size(); i++) {
        values[i] = min + i;
    }

    // Generate
    std::shuffle(values.begin(), values.end(), m_engine);
    if (count) {
        values.resize(count);
    }

    return values;
}

bool RandomGenerator::generateAction(double chance)
{
    std::uniform_real_distribution<double> distr(0.0, 1.0);

    double result = distr(m_engine);
    if (result <= chance) {
        return true;
    }

    return false;
}
