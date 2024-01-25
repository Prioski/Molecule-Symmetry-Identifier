#include <iostream>
#include <array>
#include "Vector.h"
#include "Matrix.h"
/*
template<int n>
class Matrix
{
private:
    std::array<std::array<int, n>, n> mat{};
public:
    Matrix(std::array<std::array<int, n>, n> input = std::array<std::array<int, n>, n>{})
    {
        for (int i=0; i < n; i++)
        {
            for (int j=0; j < n; j++)
                mat[i][j] = input[j][i];
        }
    }

    std::array<int, n> operator[](int obj) const
    {
        return mat[obj];
    }
    std::array<int, n>& operator[](int obj)
    {
        return mat[obj];
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                std::cout << mat[j][i] << " ";
            std::cout << '\n';
        }
    }

    Matrix<n> operator+(Matrix<n> obj)
    {
        Matrix<n> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                res[i][j] = obj[i][j] + mat[i][j];
        }
        return res;
    }
    void operator=(Matrix<n> obj)
    {
        Matrix<n> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                mat[i][j] = obj[i][j];
        }
    }
    Vector<n> operator*(Vector<n> vec)
    {
        Vector<n> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                res[i] += (vec[j] * mat[j][i]);
        }
        return res;
    }

    Matrix<n> operator*(Matrix<n> obj)
    {
        Matrix<n> res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res[j][i] += mat[k][i] * obj[j][k];
                }
            }
        }
        return res;
    }
};
*/

template <int n>
std::array<int, n> Matrix<n>::operator[](int obj) const
{
    return mat[obj];
}

template <int n>
std::array<int, n>& Matrix<n>::operator[](int obj)
{
    return mat[obj];
}

template <int n>
void Matrix<n>::print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << mat[j][i] << " ";
        std::cout << '\n';
    }
}

template <int n>
Matrix<n> Matrix<n>::operator+(Matrix<n> obj)
{
    Matrix<n> res;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            res[i][j] = obj[i][j] + mat[i][j];
    }
    return res;
}

template <int n>
void Matrix<n>::operator=(Matrix<n> obj)
{
    Matrix<n> res;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            mat[i][j] = obj[i][j];
    }
}

template <int n>
Vector<n> Matrix<n>::operator*(Vector<n> vec)
{
    Vector<n> res;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            res[i] += (vec[j] * mat[j][i]);
    }
    return res;
}
template <int n>
Matrix<n> Matrix<n>::operator*(Matrix<n> obj)
{
    Matrix<n> res;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[j][i] += mat[k][i] * obj[j][k];
            }
        }
    }
    return res;
}

template class Matrix<2>;
template class Matrix<3>;
template class Matrix<4>;
template class Matrix<5>;
template class Matrix<6>;