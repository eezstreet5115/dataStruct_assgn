#include <iostream>
using namespace std;

#define MAX 20

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1; // stack empty
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << val << "\n";
            return;
        }
        arr[++top] = val;
        cout << val << " pushed into stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek.\n";
            return;
        }
        cout << "Top element: " << arr[top] << "\n";
    }
};

int main() {
    Stack st;
    int choice, val;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                st.push(val);
                break;

            case 2:
                st.pop();
                break;

            case 3:
                if (st.isEmpty()) cout << "Stack is empty.\n";
                else cout << "Stack is not empty.\n";
                break;

            case 4:
                if (st.isFull()) cout << "Stack is full.\n";
                else cout << "Stack is not full.\n";
                break;

            case 5:
                st.display();
                break;

            case 6:
                st.peek();
                break;

            case 7:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
