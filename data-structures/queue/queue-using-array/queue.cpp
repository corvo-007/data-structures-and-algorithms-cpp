#include <iostream>
#include "queue.h"

using namespace std;


int main() {
    Queue<int> queue(5);

    cout << queue.size() << '\n';
    cout << queue.isEmpty() << '\n';

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    queue.pop();
    queue.pop();

    queue.push(6);

    cout << queue.front() << '\n';

    queue.pop();
    queue.pop();
    queue.pop();
    
    cout << queue.front() << '\n';
    cout << queue.size() << '\n';
    cout << queue.isEmpty() << '\n';
    cout << queue.pop() << '\n';
    cout << queue.size() << '\n';
    cout << queue.isEmpty() << '\n';
}