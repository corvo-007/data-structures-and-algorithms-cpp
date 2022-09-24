#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    Fraction f3 = f1 * f2;
    f1.print();
    f2.print();
    f3.print();
}