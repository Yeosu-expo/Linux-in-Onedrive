#include <iostream>
#include <string>
#include "MyStack.h"
using namespace std;

int main() {
        MyStack<int> s;
        s.pop();
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);

        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();

        return 0;
}

