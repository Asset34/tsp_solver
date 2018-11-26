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

std::vector<int> RandomGenerator::generateCombination(int min, int max, int count)
{
    // Create range vector
    std::vector<int> values(max - min + 1);
    for (int i = 0; i < values.size(); i++) {
        values[i] = min + i;
    }

    // Generate
    std::shuffle(values.begin(), values.end(), m_engine);
    values.resize(count);

    return values;
}
