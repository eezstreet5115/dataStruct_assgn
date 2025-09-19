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

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return val;
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

// Function to interleave
void interleaveQueue(Queue &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements. Cannot interleave!\n";
        return;
    }

    Queue firstHalf;

    int half = n / 2;

    // Move first half to another queue
    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.dequeue());
    }

    // Now interleave
    for (int i = 0; i < half; i++) {
        q.enqueue(firstHalf.dequeue()); // from first half
        q.enqueue(q.dequeue());         // from second half
    }
}

int main() {
    Queue q;
    int n, val;
    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }

    cout << "Original Queue: ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}
