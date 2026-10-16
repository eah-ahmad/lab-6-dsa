// Muhammad Ahmad | CMS 542432 | BSCS-15-D
// Lab 06, Q6 - customer service queue (menu driven)

#include <iostream>
using namespace std;

const int CAP = 5;
int items[CAP];
int front = -1;
int rear = -1;
int nextTag = 101;   // token number handed to the next customer

// Note for the demo: this is a plain linear queue, so once rear reaches
// index 4 nobody can be added, even if some customers were already served.
// Space only comes back when the queue becomes completely empty and resets.

void enqueue(int value) {
    if (rear == CAP - 1) {
        cout << "can't add a customer, the queue is blocked (rear is at the end)" << endl;
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    items[rear] = value;
    nextTag++;
    cout << "customer added, token " << value << endl;
}

void dequeue() {
    if (front == -1) {
        cout << "no customers waiting" << endl;
        return;
    }
    int served = items[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    cout << "now serving token " << served << endl;
}

void peekFront() {
    if (front == -1) {
        cout << "no customers waiting" << endl;
        return;
    }
    cout << "next in line is token " << items[front] << endl;
}

void display() {
    if (front == -1) {
        cout << "queue is empty" << endl;
        return;
    }
    cout << "waiting (front to rear): ";
    for (int slot = front; slot <= rear; slot++) {
        cout << items[slot] << " ";
    }
    cout << endl;
}

int main() {
    int pick = 0;

    do {
        cout << "\n1. Add customer" << endl;
        cout << "2. Serve next" << endl;
        cout << "3. View next" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "choice: ";
        cin >> pick;

        switch (pick) {
            case 1:
                enqueue(nextTag);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peekFront();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "bye" << endl;
                break;
            default:
                cout << "invalid choice, pick 1 to 5" << endl;
        }
    } while (pick != 5);

    return 0;
}
