#pragma once

template<int n>
class Matrix
{
private:
    std::array<std::array<int, n>, n> mat{};
public:
    Matrix(std::array<std::array<int, n>, n> input = std::array<std::array<int, n>, n>{})
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                mat[i][j] = input[j][i];
        }
    }
    std::array<int, n> operator[](int obj) const;
    std::array<int, n>& operator[](int obj);
    void print();
    Matrix<n> operator+(Matrix<n> obj);
    void operator=(Matrix<n> obj);
    Vector<n> operator*(Vector<n> vec);
    Matrix<n> operator*(Matrix<n> obj);
};