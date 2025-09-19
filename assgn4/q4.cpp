#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Queue {
    char arr[MAX];
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

    void enqueue(char c) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = c;
    }

    char dequeue() {
        if (isEmpty()) return '\0';
        char val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return val;
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};

void firstNonRepeating(char str[]) {
    Queue q;
    int count[256] = {0}; // frequency table

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // increase count
        count[(int)ch]++;

        // enqueue char
        q.enqueue(ch);

        // remove all repeating chars from front
        while (!q.isEmpty() && count[(int)q.peek()] > 1) {
            q.dequeue();
        }

        // print result
        if (q.isEmpty()) cout << -1 << " ";
        else cout << q.peek() << " ";
    }
    cout << "\n";
}

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin.getline(str, MAX);

    cout << "First non-repeating characters: ";
    firstNonRepeating(str);

    return 0;
}
