#include <iostream>
using namespace std;

#define MAX 5  // size of circular queue

class CircularQueue {
    int arr[MAX];
    int front = -1; int rear = -1;

public:
    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << val << "\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = val;
        cout << val << " enqueued to circular queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued from circular queue.\n";
        if (front == rear) {
            front = rear = -1; // reset queue
        } else {
            front = (front + 1) % MAX;
        }
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
        cout << "Circular Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue cq;
    int choice, val;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
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
                cq.enqueue(val);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                if (cq.isEmpty()) cout << "Queue is empty.\n";
                else cout << "Queue is not empty.\n";
                break;
            case 4:
                if (cq.isFull()) cout << "Queue is full.\n";
                else cout << "Queue is not full.\n";
                break;
            case 5:
                cq.display();
                break;
            case 6:
                cq.peek();
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
