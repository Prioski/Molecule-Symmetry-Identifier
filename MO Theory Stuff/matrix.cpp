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
    Vector<n> operator=(Vector<n> obj)
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
};


class Vector2D
{
private:
    std::array<int, 2> vec{};
public:
    Vector2D(int a_1 = 0, int a_2 = 0)
    {
        vec[0] = a_1;
        vec[1] = a_2;
    }

    int operator[](int obj) const
    {
        return vec[obj];
    }

    int& operator[](int obj)
    {
        return vec[obj];
    }

    bool operator==(Vector2D obj)
    {
        return (vec[0] == obj[0] and vec[1] == obj[1]);
    }

    Vector2D operator+(Vector2D obj)
    {
        Vector2D res;
        res[0] = vec[0] + obj[0];
        res[1] = vec[1] + obj[1];
        return res;
    }
    void print()
    {
        std::cout << "(" << vec[0] << ", " << vec[1] << ")" << '\n';
    }
};

class Matrix2D
{
private:
    std::array<std::array<int, 2>, 2> mat{};
public:
    Matrix2D(int a_1 = 0, int a_2 = 0, int b_1 = 0, int b_2 = 0)
    {
        mat[0][0] = a_1;
        mat[0][1] = b_1;
        mat[1][0] = a_2;
        mat[1][1] = b_2;
    }

    Matrix2D operator+(Matrix2D rhs)
    {
        Matrix2D res;
        res[0][0] = rhs[0][0] + mat[0][0];
        res[1][0] = rhs[1][0] + mat[1][0];
        res[0][1] = rhs[0][1] + mat[0][1];
        res[1][1] = rhs[1][1] + mat[1][1];
        return res;
    }

    Vector2D operator*(Vector2D obj)
    {
        Vector2D res;
        res[0] = (mat[0][0] * obj[0]) + (mat[1][0] * obj[1]);
        res[1] = (mat[1][0] * obj[0]) + (mat[1][1] * obj[1]);
        return res;
    }

    Matrix2D operator*(Matrix2D obj)
    {
        Matrix2D res;
        res[0][0] = (mat[0][0] * obj[0][0]) + (mat[1][0] * obj[0][1]);
        res[1][0] = (mat[0][0] * obj[1][0]) + (mat[1][0] * obj[1][1]);
        res[0][1] = (mat[0][1] * obj[0][0]) + (mat[1][1] * obj[0][1]);
        res[1][1] = (mat[0][1] * obj[1][0]) + (mat[1][1] * obj[1][1]);
        return res;
    }

    std::array<int, 2> operator[](int obj) const
    {
        return mat[obj];
    }
    std::array<int, 2>& operator[](int obj)
    {
        return mat[obj];
    }
    void print()
    {
        std::cout << mat[0][0] << " " << mat[1][0] << '\n' << mat[0][1] << " " << mat[1][1];
    }
};



int main()
{
    //Vector<5> vec{ {0, 1, 3, 4, 2} };
    //Vector<5> vec2{};
    //Vector<5> res{ vec + vec2 };
    //res.print();

    Matrix<2> mat{ {1, 2, 3, 4} };
    Matrix<2> mat2{ {10, 20, 30, 40} };
    Matrix<2> res = mat + mat2;
    res.print();
    return 0;
}