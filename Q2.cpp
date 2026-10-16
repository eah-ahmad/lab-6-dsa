// Muhammad Ahmad | CMS 542432 | BSCS-15-D
// Lab 06, Q2 - stack using a singly linked list (head = top)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "pushed " << value << endl;
}

void pop() {
    if (top == nullptr) {
        cout << "can't pop, stack is empty" << endl;
        return;
    }
    Node* newNode = top;
    int gone = newNode->data;
    top = top->next;
    delete newNode;
    cout << "popped " << gone << endl;
}

void peek() {
    if (top == nullptr) {
        cout << "can't peek, stack is empty" << endl;
        return;
    }
    cout << "top element is " << top->data << endl;
}

void display() {
    if (top == nullptr) {
        cout << "stack is empty" << endl;
        return;
    }
    cout << "stack, top to bottom: ";
    Node* walker = top;
    while (walker != nullptr) {
        cout << walker->data << " ";
        walker = walker->next;
    }
    cout << endl;
}

int main() {
    push(5);
    push(15);
    push(25);
    display();
    pop();
    peek();
    display();

    // empty pop test
    cout << "\n-- empty pop test --" << endl;
    pop();
    pop();
    pop();   

    push(7);
    push(8);
    display();

   
    while (top != nullptr) {
        Node* newNode = top;
        top = top->next;
        delete newNode;
    }
    cout << "remaining nodes freed, top is " << (top == nullptr ? "null" : "not null") << endl;

    return 0;
}
