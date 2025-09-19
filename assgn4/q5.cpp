#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }

    bool isFull() { return rear == SIZE - 1; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Overflow\n"; return; }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) { cout << "Queue Underflow\n"; return -1; }
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return val;
    }

    int getSize() { return isEmpty() ? 0 : rear - front + 1; }

    int getFront() { return isEmpty() ? -1 : arr[front]; }
};

class StackUsingOneQueue {
    Queue q;
public:
    void push(int x) {
        q.enqueue(x);
        int n = q.getSize();
        // rotate queue to make x at front
        for (int i = 0; i < n - 1; i++)
            q.enqueue(q.dequeue());
    }

    void pop() {
        if (q.isEmpty()) { cout << "Stack Underflow\n"; return; }
        cout << "Popped: " << q.dequeue() << endl;
    }

    void top() {
        if (q.isEmpty()) { cout << "Stack is Empty\n"; return; }
        cout << "Top: " << q.getFront() << endl;
    }

    bool isEmpty() { return q.isEmpty(); }
};

int main() {
    StackUsingOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.top();
    s.pop();
    s.top();
    s.pop();
    s.pop();
    s.pop(); // underflow test
    return 0;
}
