#include <iostream>
#include <array>
#include "Vector.h"

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