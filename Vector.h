#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
    int* array;
    int size;

public:
    Vector();
    Vector(int n);
    Vector(const int* arr, int n);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    ~Vector();

    int& operator[](int index);
    const int& operator[](int index) const;
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);

    bool operator<(const Vector& other) const;
};

#endif
