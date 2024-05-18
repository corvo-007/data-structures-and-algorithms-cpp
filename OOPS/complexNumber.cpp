#include <iostream>
#include "complexNumber.h"

int main() {
    int real1, imaginary1, real2, imaginary2;

    std::cin >> real1 >> imaginary1;
    std::cin >> real2 >> imaginary2;

    ComplexNumber c1(real1, imaginary1);
    ComplexNumber c2(real2, imaginary2);

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
}