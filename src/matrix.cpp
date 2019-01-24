#include "matrix.hpp"

#include <cmath>

#include <utills/randomgenerator.hpp>

Matrix::Matrix(int size, double defaultValue)
    : m_data(size, std::vector<double>(size, defaultValue))
{
}

const std::vector<double> &Matrix::operator[](int row) const
{
    return m_data[row];
}

std::vector<double> &Matrix::operator[](int row)
{
    return m_data[row];
}

int Matrix::getSize() const
{
    return m_data.size();
}

Matrix &Matrix::operator*(double value)
{
    for (int i = 0; i < getSize(); i++) {
        for (int j = 0; j < getSize(); j++) {
            m_data[i][j] *= value;
        }
    }

    return *this;
}

Matrix &operator*(double value, Matrix &matrix)
{
    return matrix * value;
}
