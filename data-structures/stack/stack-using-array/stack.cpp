#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.isEmpty() << '\n';
    cout << s.size() << '\n';
    cout << s.pop() << '\n';
    cout << s.pop() << '\n';
    cout << s.pop() << '\n';
    cout << s.pop() << '\n';
    cout << s.isEmpty() << '\n';
    cout << s.size() << '\n';
    cout << s.pop() << '\n';
    cout << s.isEmpty() << '\n';
    cout << s.size() << '\n';
    cout << s.pop();
}