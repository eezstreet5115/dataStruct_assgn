#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << val << "\n";
            return;
        }
        if (front == -1) 
            front = 0; // first element
        arr[++rear] = val;
        cout << val << " enqueued to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued from queue.\n";
        if (front == rear) {
            front = rear = -1; // reset when queue becomes empty
        }
        else {
            front++;
        }
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek.\n";
            return;
        }
        cout << "Front element: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, val;

    do {
        cout << "\n Queue Menu \n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                if (q.isEmpty()) cout << "Queue is empty.\n";
                else cout << "Queue is not empty.\n";
                break;
            case 4:
                if (q.isFull()) cout << "Queue is full.\n";
                else cout << "Queue is not full.\n";
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
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
