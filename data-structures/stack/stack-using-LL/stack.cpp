#include <iostream>
#include "stack.h"

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    std::cout << stack.isEmpty() << '\n';
    std::cout << stack.size() << '\n';

    std::cout << stack.pop() << '\n';
    std::cout << stack.pop() << '\n';
    std::cout << stack.pop() << '\n';
    std::cout << stack.pop() << '\n';

    std::cout << stack.isEmpty() << '\n';
    std::cout << stack.size() << '\n';

    std::cout << stack.top() << '\n';
    stack.push(100);
    std::cout << stack.top() << '\n';

    std::cout << stack.pop() << '\n';

    std::cout << stack.isEmpty() << '\n';
    std::cout << stack.size() << '\n';
}