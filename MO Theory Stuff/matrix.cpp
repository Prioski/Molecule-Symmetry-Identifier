#include <iostream>
#include <array>

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
    Vector2D vect(1, 2);
    Matrix2D matrix(0, 1, 1, 0);
    Vector2D result = matrix * vect;
    result.print();
    return 0;
}