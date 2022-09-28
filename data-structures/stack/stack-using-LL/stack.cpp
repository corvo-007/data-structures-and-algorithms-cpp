#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << stack.isEmpty() << '\n';
    cout << stack.size() << '\n';

    cout << stack.pop() << '\n';
    cout << stack.pop() << '\n';
    cout << stack.pop() << '\n';
    cout << stack.pop() << '\n';

    cout << stack.isEmpty() << '\n';
    cout << stack.size() << '\n';

    cout << stack.top() << '\n';
    stack.push(100);
    cout << stack.top() << '\n';

    cout << stack.pop() << '\n';

    cout << stack.isEmpty() << '\n';
    cout << stack.size() << '\n';
}