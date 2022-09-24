#include <iostream>
using namespace std;

class DynamicArray {
    int *data;
    int nextIndex;
    int capacity;

    public:

    DynamicArray() {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    DynamicArray(DynamicArray const &arr) {
        data = new int[arr.capacity];
        for (int i = 0; i < arr.capacity; i++) {
            data[i] = arr.data[i];
        }
        nextIndex = arr.nextIndex;
        capacity = arr.capacity;
    }

    void operator=(DynamicArray const &arr) {
        data = new int[arr.capacity];
        for (int i = 0; i < arr.capacity; i++) {
            data[i] = arr.data[i];
        }
        nextIndex = arr.nextIndex;
        capacity = arr.capacity;
    }

    void add(int element) {
        if (nextIndex == capacity) {
            int *temp = data;
            data = new int[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                data[i] = temp[i];
            }
            delete [] temp;
            capacity *= 2;
        }
        data[nextIndex++] = element;
    }

    void set(int i, int element) {
        if (i >= 0 && i < nextIndex) {
            data[i] = element;
        }
        else if (i == nextIndex) {
            add(element);
        }
        else {
            return ;
        }
    }

    int get(int i) const {
        if (i < 0 || i >= nextIndex) {
            return -1;
        }
        return data[i];
    }

    void print() const {
        for (int i = 0; i < nextIndex; i++) {
            cout << data[i] << ' ';
        }
        cout << '\n';
    }

    ~DynamicArray() {
        delete [] data;
    }
};