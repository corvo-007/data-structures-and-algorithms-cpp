#include <iostream>
#include "polynomial.h"

int main() {
    int count1,count2,choice;
    std::cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        std::cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        std::cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    std::cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        std::cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        std::cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }

    first.print();
    second.print();
    
    std::cin >> choice;
    
    Polynomial result;
    switch(choice) {
        case 1:
            result = first + second;
            result.print();
            break;
        case 2 :
            result = first - second;
            result.print();
            break;
        case 3 :
            result = first * second;
            result.print();
            break;
        case 4 :
        {
            Polynomial third(first);
            if(third == second) {
                std::cout << "true\n";
            }
            else {
                std::cout << "false\n";
            }
            break;
        }
        case 5 :
        {
            Polynomial fourth(first);
            if(fourth == first) {
                std::cout << "true\n";
            }
            else {
                std::cout << "false\n";
            }
            break;
        }
    }
}