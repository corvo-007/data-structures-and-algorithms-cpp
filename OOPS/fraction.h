#include <iostream>

class Fraction {
    int numerator;
    int denominator;

    public:
    
    Fraction(int numerator, int denominator) {
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void print() const {
        std::cout << this->numerator << " / " << denominator << '\n';
    }

    void simplify() {
        int gcd = 1;
        int j = std::min(numerator, denominator);
        for (int i = 1; i <= j; i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                gcd = i;
            }
        }
        numerator /= gcd;
        denominator /= gcd;
    }

    Fraction add(Fraction const &f) const {
        int lcm = denominator * f.denominator;
        int x = lcm / denominator;
        int y = lcm / f.denominator;

        int num = x * numerator + (y * f.numerator);

        Fraction sum(num, lcm);
        sum.simplify();
        return sum;
    }
    
    Fraction operator+(Fraction const &f) const {
        int lcm = denominator * f.denominator;
        int x = lcm / denominator;
        int y = lcm / f.denominator;

        int num = x * numerator + (y * f.numerator);

        Fraction sum(num, lcm);
        sum.simplify();
        return sum;
    }

    Fraction multiply(Fraction const &f) const {
        Fraction product(numerator * f.numerator, denominator * f.denominator);
        product.simplify();
        return product;
    }

    Fraction operator*(Fraction const &f) const {
        Fraction product(numerator * f.numerator, denominator * f.denominator);
        product.simplify();
        return product;
    }

    bool operator==(Fraction const &f) const {
        return numerator == f.numerator && denominator == f.denominator;
    }

    // Pre Increment
    Fraction& operator++() {
        numerator += denominator;
        simplify();
        return *this;
    }

    // Post Increment
    Fraction operator++(int) {
        Fraction save(numerator, denominator);
        numerator += denominator;
        simplify();
        save.simplify();
        return save;
    }

    Fraction& operator+=(Fraction const &f) {
        int lcm = denominator * f.denominator;
        int x = lcm / denominator;
        int y = lcm / f.denominator;

        int num = x * numerator + (y * f.numerator);

        numerator = num;
        denominator = lcm;
        simplify();
        return *this;
    }
};