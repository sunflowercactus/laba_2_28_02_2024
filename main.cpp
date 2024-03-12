#include "Vector.h"
#include <iostream>
#include <fstream>

Vector::Vector() : array(nullptr), size(0) {}

Vector::Vector(int n) : size(n) {
    array = new int[n];
}

Vector::Vector(const int* arr, int n) : size(n) {
    array = new int[n];
    std::copy(arr, arr + n, array);
}

Vector::Vector(const Vector& other) : size(other.size) {
    array = new int[other.size];
    std::copy(other.array, other.array + other.size, array);
}

Vector::Vector(Vector&& other) noexcept : array(other.array), size(other.size) {
    other.array = nullptr;
    other.size = 0;
}

Vector::~Vector() {
    delete[] array;
}

int& Vector::operator[](int index) {
    return array[index];
}

const int& Vector::operator[](int index) const {
    return array[index];
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] array;
        size = other.size;
        array = new int[other.size];
        std::copy(other.array, other.array + other.size, array);
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) {
    if (this != &other) {
        delete[] array;
        array = other.array;
        size = other.size;
        other.array = nullptr;
        other.size = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    for (int i = 0; i < vec.size; ++i) {
        os << vec.array[i] << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Vector& vec) {
    for (int i = 0; i < vec.size; ++i) {
        is >> vec.array[i];
    }
    return is;
}

bool Vector::operator<(const Vector& other) const {
    for (int i = 0; i < size && i < other.size; ++i) {
        if (array[i] < other.array[i]) return true;
        else if (array[i] > other.array[i]) return false;
    }
    return false;
}
void readVectorsFromFile(const std::string& filename, Vector& vec1, Vector& vec2) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int size1, size2;
        file >> size1;
        vec1 = Vector(size1);
        file >> vec1;
        file >> size2;
        vec2 = Vector(size2);
        file >> vec2;
        file.close();
    }
    else {
        std::cerr << "Error opening file for reading." << std::endl;
    }
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    Vector vec1, vec2;

    readVectorsFromFile("input.txt", vec1, vec2);

    std::cout << "Vector 1: " << vec1 << std::endl;
    std::cout << "Vector 2: " << vec2 << std::endl;


    outputFile << "Vector 1: " << vec1 << std::endl;
    outputFile << "Vector 2: " << vec2 << std::endl;

    if (vec1 < vec2) {
        outputFile << "Vector 1 is less than Vector 2" << std::endl;
        std::cout << "Vector 1 is less than Vector 2";
    }
    else {
        outputFile << "Vector 1 is not less than Vector 2" << std::endl;
    }

    return 0;
}
