#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
    Fraction f1(10, 3);
    Fraction f2(5, 2);

    (f1 += f2) += f2;
    f1.print();
    f2.print();
}