#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return (top == -1); }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
};

int evaluatePostfix(char postfix[]) {
    Stack st;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If operand (digit), push it
        if (ch >= '0' && ch <= '9') {
            st.push(ch - '0'); // convert char digit to int
        }
        // If operator, pop two and apply
        else {
            int op2 = st.pop();
            int op1 = st.pop();
            int res;
            switch (ch) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                default: 
                    cout << "Unsupported operator: " << ch << "\n";
                    return -1;
            }
            st.push(res);
        }
    }
    return st.pop(); // final result
}

int main() {
    char postfix[MAX];
    cout << "Enter a Postfix expression (single-digit operands): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << "\n";
    return 0;
}
