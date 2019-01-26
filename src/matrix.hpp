#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

class Matrix
{
public:
    Matrix(int size = 0, double defaultValue = 0.0);

    const std::vector<double> &operator[](int row) const;
    std::vector<double> &operator[](int row);

    int getSize() const;

    void multiply(int scalar);

private:
    std::vector<std::vector<double>> m_data;

};

#endif // MATRIX_HPP
