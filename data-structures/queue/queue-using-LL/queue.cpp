#include <iostream>
#include "queue.h"

int main() {
    Queue<int> q;
    std::cout << q.size() << '\n';
    std::cout << q.isEmpty() << '\n';

    q.push(1);
    q.push(2);

    std::cout << q.size() << '\n';
    std::cout << q.isEmpty() << '\n';

    q.push(3);
    q.push(4);
    q.push(5);

    std::cout << q.size() << '\n';
    std::cout << q.isEmpty() << '\n';

    std::cout << q.pop() << '\n';
    std::cout << q.pop() << '\n';

    std::cout << q.size() << '\n';
    std::cout << q.isEmpty() << '\n';

    q.push(6);
    q.push(7);

    std::cout << q.size() << '\n';
    std::cout << q.isEmpty() << '\n';

    std::cout << q.pop() << '\n';
    std::cout << q.pop() << '\n';
    std::cout << q.pop() << '\n';

    std::cout << q.size() << '\n';
    std::cout << q.isEmpty() << '\n';

    std::cout << q.pop() << '\n';
    std::cout << q.pop() << '\n';

    std::cout << q.size() << '\n';
    std::cout << q.isEmpty() << '\n';

    q.push(8);

    std::cout << q.front() << '\n';

    std::cout << q.size() << '\n';
    std::cout << q.isEmpty() << '\n';

    q.pop();
    std::cout << q.front() << '\n';

    std::cout << q.size() << '\n';
    std::cout << q.isEmpty() << '\n';

}