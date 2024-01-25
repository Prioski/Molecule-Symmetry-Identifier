#include <iostream>
#include <array>

template<int n>
class Vector
{
private:
    std::array<int, n> vec{};
public:
    Vector(std::array<int, n> input = std::array<int, n>{})
    {
        for (int i = 0; i < n; i++)
            vec[i] = input[i];
    }

    void print()
    {
        std::cout << "(";
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
                std::cout << vec[i];
            else
                std::cout << vec[i] << ", ";
        }
        std::cout << ")" << '\n';
    }

    int operator[](int obj) const
    {
        return vec[obj];
    }

    int& operator[](int obj)
    {
        return vec[obj];
    }

    Vector<n> operator+(Vector<n> obj)
    {
        Vector<n> res;
        for (int i = 0; i < n; i++)
            res[i] = vec[i] + obj[i];
        return res;
    }

    bool operator==(Vector<n> obj)
    {
        for (int i = 0; i < n; i++)
        {
            if (vec[i] != obj[i])
                return false;
        }
        return true;
    }
    void operator=(Vector<n> obj)
    {
        for (int i = 0; i < n; i++)
            vec[i] = obj[i];
    }
};

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

/*
int main()
{
    Vector<3> vec{ {1, 2, 3} };
    //Vector<5> vec2{};
    //Vector<5> res{ vec + vec2 };
    //res.print();

    Matrix<3> mat{ {1, 2, 3, 4, 5, 6, 7, 8, 9} };
    Matrix<3> mat2{ {10, 11, 12, 13, 14, 15, 16, 17, 18} };
    Matrix<3> res = mat * mat2;
    res.print();
    return 0;
}
*/