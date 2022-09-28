#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue<int> q;
    cout << q.size() << '\n';
    cout << q.isEmpty() << '\n';

    q.push(1);
    q.push(2);

    cout << q.size() << '\n';
    cout << q.isEmpty() << '\n';

    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.size() << '\n';
    cout << q.isEmpty() << '\n';

    cout << q.pop() << '\n';
    cout << q.pop() << '\n';

    cout << q.size() << '\n';
    cout << q.isEmpty() << '\n';

    q.push(6);
    q.push(7);

    cout << q.size() << '\n';
    cout << q.isEmpty() << '\n';

    cout << q.pop() << '\n';
    cout << q.pop() << '\n';
    cout << q.pop() << '\n';

    cout << q.size() << '\n';
    cout << q.isEmpty() << '\n';

    cout << q.pop() << '\n';
    cout << q.pop() << '\n';

    cout << q.size() << '\n';
    cout << q.isEmpty() << '\n';

    q.push(8);

    cout << q.front() << '\n';

    cout << q.size() << '\n';
    cout << q.isEmpty() << '\n';

    q.pop();
    cout << q.front() << '\n';

    cout << q.size() << '\n';
    cout << q.isEmpty() << '\n';

}