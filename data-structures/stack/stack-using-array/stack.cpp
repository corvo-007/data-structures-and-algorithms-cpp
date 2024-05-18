#include <iostream>
#include "stack.h"

int main() {
    Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    std::cout << s.isEmpty() << '\n';
    std::cout << s.size() << '\n';
    std::cout << s.pop() << '\n';
    std::cout << s.pop() << '\n';
    std::cout << s.pop() << '\n';
    std::cout << s.pop() << '\n';
    std::cout << s.isEmpty() << '\n';
    std::cout << s.size() << '\n';
    std::cout << s.pop() << '\n';
    std::cout << s.isEmpty() << '\n';
    std::cout << s.size() << '\n';
    std::cout << s.pop();
}