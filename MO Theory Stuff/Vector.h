#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <iostream>

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
    void print();
    //int operator[](int obj) const;
    //int& operator[](int obj);
    //Vector<n> operator+(Vector<n> obj);
    //bool operator==(Vector<n> obj);
    //void operator=(Vector<n> obj);
};

#endif