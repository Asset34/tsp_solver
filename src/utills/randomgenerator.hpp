#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

#include <random>
#include <vector>

class RandomGenerator
{
public:
    static bool generateBool();
    static int generateInt(int min, int max);
    static std::vector<int> generateCombination(int min, int max);

private:
    static std::default_random_engine m_engine;
    static std::uniform_int_distribution<int> m_boolDistr;

};

#endif // RANDOMGENERATOR_HPP
