// Muhammad Ahmad | CMS 542432 | BSCS-15-D
// Lab 06, Q5 - removing from a linear array queue

#include <iostream>
using namespace std;

const int CAP = 5;
int items[CAP];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == CAP - 1) {
        cout << "insertion blocked, rear is at the last slot (" << value << " not added)" << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    items[rear] = value;
    cout << "added " << value << endl;
}

void dequeue() {
    if (front == -1) {
        cout << "can't remove, queue is empty" << endl;
        return;
    }
    int gone = items[front];
    if (front == rear) {
        // that was the last one, start over
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    cout << "removed " << gone << endl;
}

void peekFront() {
    if (front == -1) {
        cout << "nothing at the front, queue is empty" << endl;
        return;
    }
    cout << "front element is " << items[front] << endl;
}

void display() {
    if (front == -1) {
        cout << "queue is empty, nothing to display" << endl;
        return;
    }
    cout << "queue, front to rear: ";
    for (int slot = front; slot <= rear; slot++) {
        cout << items[slot] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    peekFront();
    display();

    cout << "\n-- emptying the queue --" << endl;
    dequeue();
    dequeue();
    dequeue();   // already empty
    display();

    cout << "\n-- insert after reset --" << endl;
    enqueue(40);
    display();
    peekFront();

    return 0;
}
