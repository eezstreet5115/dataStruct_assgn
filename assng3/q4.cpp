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
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack st;
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if ((ch >= 'a' && ch <= 'z') || 
            (ch >= 'A' && ch <= 'Z') || 
            (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch;
        }
        // If '(', push
        else if (ch == '(') {
            st.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix[k++] = st.pop();
            }
            st.pop(); // remove '('
        }
        // Operator
        else {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) {
                postfix[k++] = st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.isEmpty()) {
        postfix[k++] = st.pop();
    }
    postfix[k] = '\0'; // null-terminate
}

int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter Infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << "\n";
    return 0;
}
