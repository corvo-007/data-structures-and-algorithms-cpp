#include <iostream>
#include "queue.h"

int main() {
    Queue<int> queue(5);

    std::cout << queue.size() << '\n';
    std::cout << queue.isEmpty() << '\n';

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    queue.pop();
    queue.pop();

    queue.push(6);

    std::cout << queue.front() << '\n';

    queue.pop();
    queue.pop();
    queue.pop();
    
    std::cout << queue.front() << '\n';
    std::cout << queue.size() << '\n';
    std::cout << queue.isEmpty() << '\n';
    std::cout << queue.pop() << '\n';
    std::cout << queue.size() << '\n';
    std::cout << queue.isEmpty() << '\n';
}