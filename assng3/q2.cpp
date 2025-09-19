#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return (top == -1); }
    bool isFull() { return (top == MAX - 1); }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow! " << c << "\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return '\0';
        }
        return arr[top--];
    }
};

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;

    Stack st;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        st.push(str[i]);
    }

    cout << "Reversed string: ";
    while (!st.isEmpty()) {
        cout << st.pop();
    }
    cout << "\n";

    return 0;
}
