// Muhammad Ahmad | CMS 542432 | BSCS-15-D
// Lab 06, Q3 - reverse a word with a char stack

#include <iostream>
#include <string>
using namespace std;

const int LIMIT = 20;
char letterBox[LIMIT];
int top = -1;

void push(char ch) {
    if (top == LIMIT - 1) {
        cout << "stack full" << endl;
        return;
    }
    top++;
    letterBox[top] = ch;
}

char pop() {
    char out = letterBox[top];
    top--;
    return out;
}

int main() {
    string word;
//yarra , main yahhan na aik aik kr k letters lay rhha
    while (true) {
        cout << "enter a word (up to 20 letters), or 0 to quit: ";
        cin >> word;

        if (word == "0") {
            break;
        }

        int n = word.length();
        if (n > LIMIT) {
            cout << "that's " << n << " characters, max is " << LIMIT << endl;
            continue;
        }

        top = -1;
        for (int p = 0; p < n; p++) {
            push(word[p]);
        }

        cout << "reversed: ";
        while (top != -1) {
            cout << pop();
        }
        cout << endl;
    }

    return 0;
}
