#include <iostream>

#include "stack.hpp"

template <typename T, typename Container>
void filling(Stack<T, Container>& stack) {
    while (!stack.empty()) {
        stack.pop();
    }

    for (size_t i = 1; i <= 5; ++i) {
        stack.push(i);
    }
}

int main() {
    Stack<int> myStack1;

    filling(myStack1);
    myStack1.pop();

    cout << "stack1: ";
    print(myStack1);
    cout << endl;


    Stack<int> myStack2;

    filling(myStack2);

    cout << "stack2: ";
    print(myStack2);
    cout << endl << endl;


    myStack1.swap(myStack2);

    cout << "after swap:" << endl;


    cout << "stack1: ";
    print(myStack1);
    cout << endl;
    
    cout << "stack2: ";
    print(myStack2);
    cout << endl;

    cout << "stack1 < stack2 == " << (myStack1 < myStack2) << endl;
    cout << "stack1 > stack2 == " << (myStack1 > myStack2) << endl;


    cout << endl;

    myStack1.pop();
    cout << "stack1: ";
    print(myStack1);
    cout << endl;

    myStack1.pop();
    cout << "stack1: ";
    print(myStack1);
    cout << endl;
    
    myStack1.push(5);
    cout << "stack1: ";
    print(myStack1);
    cout << endl;

    cout << "stack1: ";
    print(myStack1);
    cout << endl;
    
    cout << "stack2: ";
    print(myStack2);
    cout << endl;

    cout << "stack1 < stack2 == " << (myStack1 < myStack2) << endl;
    cout << "stack1 > stack2 == " << (myStack1 > myStack2) << endl;

    return 0;
}