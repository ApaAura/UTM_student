#include <iostream>

class Queue {
private:
    int size;
    int count;
    float* data;

public:
    Queue() {
        size = 10;
        count = 0;
        data = new float[size];
    }

    Queue(int n) {
        size = n;
        count = 0;
        data = new float[size];
    }

    Queue(const Queue& other) {
        size = other.size;
        count = other.count;
        data = new float[size];
        for (int i = 0; i < count; i++) {
            data[i] = other.data[i];
        }
    }

    ~Queue() {
        delete[] data;
    }

    void add(float value) {
        if (isFull()) {
            std::cout << "Coada este plină!\n";
            return;
        }
        data[count++] = value;
    }

    float get() {
        if (isEmpty()) {
            std::cout << "Coada este goală!\n";
            return -1;
        }
        float val = data[0];
        for (int i = 1; i < count; i++) {
            data[i - 1] = data[i];
        }
        count--;
        return val;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == size;
    }
};
