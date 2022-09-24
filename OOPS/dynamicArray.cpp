#include <iostream>
#include "dynamicArray.h"

using namespace std;

int main() {
    DynamicArray arr;

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.add(50);

    DynamicArray arr3;
    arr3 = arr;

    arr.print();
    arr3.print();

    arr.set(0, 100);
    

    arr.print();
    arr3.print();
}