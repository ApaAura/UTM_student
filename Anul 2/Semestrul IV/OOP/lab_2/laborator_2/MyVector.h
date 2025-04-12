#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class MyVector {
private:
    long* data;
    int size;

public:
    MyVector() : size(0), data(nullptr) {}

    MyVector(int s) : size(s) {
        data = new long[size];
    }

    MyVector(const MyVector& other) : size(other.size) {
        data = new long[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    ~MyVector() {
        delete[] data;
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new long[size];
            for (int i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    bool operator==(const MyVector& v) const {
        if (size != v.size) return false;
        for (int i = 0; i < size; ++i)
            if (data[i] != v.data[i]) return false;
        return true;
    }

    bool operator!=(const MyVector& v) const {
        return !(*this == v);
    }

    long Modulus() const {
        long sum = 0;
        for (int i = 0; i < size; ++i)
            sum += data[i] * data[i];
        return sqrt(sum);
    }

    bool operator<(const MyVector& v) const {
        return this->Modulus() < v.Modulus();
    }

    bool operator>(const MyVector& v) const {
        return this->Modulus() > v.Modulus();
    }

    void SetSize(int s) {
        delete[] data;
        size = s;
        data = new long[size];
    }

    int GetSize() const {
        return size;
    }

    void SetData(int index, long value) {
        if (index >= 0 && index < size)
            data[index] = value;
    }

    long GetData(int index) const {
        if (index >= 0 && index < size)
            return data[index];
        return 0;
    }

    friend MyVector operator+(const MyVector& a, const MyVector& b) {
        int minSize = min(a.size, b.size);
        MyVector result(minSize);
        for (int i = 0; i < minSize; ++i)
            result.data[i] = a.data[i] + b.data[i];
        return result;
    }

    friend MyVector operator-(const MyVector& a, const MyVector& b) {
        int minSize = min(a.size, b.size);
        MyVector result(minSize);
        for (int i = 0; i < minSize; ++i)
            result.data[i] = a.data[i] - b.data[i];
        return result;
    }

    friend istream& operator>>(istream& in, MyVector& v) {
        for (int i = 0; i < v.size; ++i) {
            cout << "Element " << i + 1 << ": ";
            in >> v.data[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const MyVector& v) {
        for (int i = 0; i < v.size; ++i) {
            out << v.data[i] << " ";
        }
        return out;
    }
};
