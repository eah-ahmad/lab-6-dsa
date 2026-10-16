// Muhammad Ahmad | CMS 542432 | BSCS-15-D
// Lab 06, Q1 - stack using an array




#include <iostream>
using namespace std;

const int CAP = 5;
int items[CAP];
int top = -1;

void push(int value) {
    if (top == CAP - 1) {
        cout << "stack is full, " << value << " was not added" << endl;
        return;
    }
    top++;
    items[top] = value;
    cout << "pushed " << value << endl;
}

void pop() {
    if (top == -1) {
        cout << "can't pop, stack is empty" << endl;
        return;
    }
    int gone = items[top];
    top--;
    cout << "popped " << gone << endl;
}

void peek() {
    if (top == -1) {
        cout << "can't peek, stack is empty" << endl;
        return;
    }
    cout << "top element is " << items[top] << endl;
}

void display() {
    if (top == -1) {
        cout << "stack is empty" << endl;
        return;
    }
    cout << "stack, top to bottom: ";
    for (int slot = top; slot >= 0; slot--) {
        cout << items[slot] << " ";
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    display();

    cout << "\n-- overflow test --" << endl;
    push(40);
    push(50);
    push(60);
    display();
    push(70);

    
    cout << "\n-- underflow test --" << endl;
    while (top != -1) {
        pop();
    }
    pop();
    peek();

    return 0;
}
