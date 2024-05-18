#include <iostream>

class Polynomial {
    int *degCoeff;
    int size;

    public:

    Polynomial() {
        degCoeff = new int[5];
        for (int i = 0; i < 5; i++) {
            degCoeff[i] = 0;
        }
        size = 5;
    }

    Polynomial(Polynomial const &p) {
        degCoeff = new int[p.size];
        for (int i = 0; i < p.size; i++) {
            degCoeff[i] = p.degCoeff[i];
        }
        size = p.size;
    }

    void operator=(Polynomial const &p) {
        delete [] degCoeff;
        degCoeff = new int[p.size];
        for (int i = 0; i < p.size; i++) {
            degCoeff[i] = p.degCoeff[i];
        }
        size = p.size;
    }

    bool allZeroes(int *arr, int start, int end) const {
        for (int i = start; i <= end; i++) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }

    bool operator==(Polynomial const &p) const {
        if (size != p.size) {
            if (size > p.size) {
                if (!allZeroes(degCoeff, p.size, size - 1)) {
                    return false;
                }
            }
            else {
                if (!allZeroes(p.degCoeff, size, p.size - 1)) {
                    return false;
                }
            }
        }
        int s = std::min(size, p.size);
        for (int i = 0; i < s; i++) {
            if (degCoeff[i] != p.degCoeff[i]) {
                return false;
            }
        }
        return true;
    }

    void setCoefficient(int deg, int coeff) {
        if(deg >= size) {
            int *temp = degCoeff;
            int oldSize = size;
            size = deg + 1;
            degCoeff = new int[size];
            for (int i = 0; i < oldSize; i++) {
                degCoeff[i] = temp[i];
            }
            delete [] temp;
            for (int i = oldSize; i < size; i++) {
                degCoeff[i] = 0;
            }
        }
        degCoeff[deg] = coeff;
    }

    Polynomial operator+(Polynomial const &p) const {
        Polynomial sum;
        int i = 0;
        while (i < size && i < p.size) {
            sum.setCoefficient(i, degCoeff[i] + p.degCoeff[i]);
            i++;
        }
        while (i < size) {
            sum.setCoefficient(i, degCoeff[i]);
            i++;
        }
        while (i < p.size) {
            sum.setCoefficient(i, p.degCoeff[i]);
            i++;
        }
        return sum;
    }

    Polynomial operator-(Polynomial const &p) const {
        Polynomial diff;
        int i = 0;
        while (i < size && i < p.size) {
            diff.setCoefficient(i, degCoeff[i] - p.degCoeff[i]);
            i++;
        }
        while (i < size) {
            diff.setCoefficient(i, degCoeff[i]);
            i++;
        }
        while (i < p.size) {
            diff.setCoefficient(i, -p.degCoeff[i]);
            i++;
        }
        return diff;
    }

    Polynomial operator*(Polynomial const &p) const {
        Polynomial prod;

        for (int i = 0; i < size; i++) {
            if (degCoeff[i] == 0) {
                continue;
            }
            for (int j = 0; j < p.size; j++) {
                if (p.degCoeff[j] == 0) {
                    continue;
                }
                int currDegValue;   // curr coefficient of a degree of product polynomial
                if (i + j >= prod.size) {
                    currDegValue = 0;
                }
                else {
                    currDegValue = prod.degCoeff[i + j];
                }
                prod.setCoefficient(i + j, currDegValue + degCoeff[i] * p.degCoeff[j]);
            }
        }
        return prod;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            if (degCoeff[i] != 0) {
                std::cout << degCoeff[i] << 'x' << i << ' ';
            }
        }
        std::cout << '\n';
    }
};