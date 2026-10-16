// Muhammad Ahmad | CMS 542432 | BSCS-15-D
// Lab 06, Q4 - inserting into a linear array queue

#include <iostream>
using namespace std;

const int LIMIT = 5;
int items[LIMIT];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == LIMIT - 1) {
        cout << "insertion blocked, rear is at the last slot (" << value << " not added)" << endl;
        return;
    }
    if (front == -1) {
        front = 0;   // very first insertion
    }
    rear++;
    items[rear] = value;
    cout << "added " << value << endl;
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
    // display before anything is inserted
    display();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    // fill the rest and push one extra
    cout << "\n-- fill test --" << endl;
    enqueue(40);
    enqueue(50);
    display();
    enqueue(60);   // should be blocked

    return 0;
}
