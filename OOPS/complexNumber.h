#include <iostream>

class ComplexNumber {
    int real;
    int imaginary;

    public:

    ComplexNumber(int real, int imaginary) {
        this -> real = real;
        this -> imaginary = imaginary;
    }

    void plus(ComplexNumber const &c) {
        real += c.real;
        imaginary += c.imaginary;
    }

    void multiply(ComplexNumber const &c) {
        int real = this -> real * c.real - (this -> imaginary * c.imaginary);
        imaginary = this -> real * c.imaginary + this -> imaginary * c.real;
        this -> real = real;
    }

    void print() {
        std::cout << real << " + i" << imaginary << '\n';
    }
};