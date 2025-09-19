#include <iostream>
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
        if (!isFull()) arr[++top] = c;
    }

    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0';
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};

bool isBalanced(char exp[]) {
    Stack st;
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty()) return false; // no matching open

            char top = st.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // mismatch
            }
        }
    }
    return st.isEmpty(); // balanced only if stack empty at end
}

int main() {
    char exp[MAX];
    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Expression has Balanced Parentheses\n";
    else
        cout << "Expression is NOT Balanced\n";

    return 0;
}
