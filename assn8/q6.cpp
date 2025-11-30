#include <iostream>
using namespace std;

void swapValues(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

void maxHeapify(int numbers[], int size, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && numbers[leftChild] > numbers[largest])
        largest = leftChild;

    if (rightChild < size && numbers[rightChild] > numbers[largest])
        largest = rightChild;

    if (largest != index) {
        swapValues(numbers[index], numbers[largest]);
        maxHeapify(numbers, size, largest);
    }
}

struct MaxPriorityQueue {
    int* data;
    int capacity;
    int currentSize;

    MaxPriorityQueue(int cap) {
        capacity = cap;
        currentSize = 0;
        data = new int[capacity];
    }

    ~MaxPriorityQueue() {
        delete[] data;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == capacity;
    }

    void insert(int value) {
        if (isFull()) {
            cout << "Priority queue is full\n";
            return;
        }

        int index = currentSize;
        data[index] = value;
        currentSize++;

        while (index != 0) {
            int parent = (index - 1) / 2;
            if (data[parent] < data[index]) {
                swapValues(data[parent], data[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    int getMax() {
        if (isEmpty()) {
            cout << "Priority queue is empty\n";
            return -1;
        }
        return data[0];
    }

    int extractMax() {
        if (isEmpty()) {
            cout << "Priority queue is empty\n";
            return -1;
        }

        int maxValue = data[0];
        data[0] = data[currentSize - 1];
        currentSize--;

        maxHeapify(data, currentSize, 0);
        return maxValue;
    }

    void show() {
        if (isEmpty()) {
            cout << "Priority queue is empty\n";
            return;
        }
        for (int i = 0; i < currentSize; i++) {
            cout << data[i];
            if (i + 1 < currentSize) cout << " ";
        }
        cout << "\n";
    }
};

int main() {
    MaxPriorityQueue queue(100);
    int choice;

    while (true) {
        cout << "\n--- Priority Queue (Heap) Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Get max\n";
        cout << "3. Extract max\n";
        cout << "4. Display internal heap array\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            queue.insert(value);
        } else if (choice == 2) {
            int mx = queue.getMax();
            if (!queue.isEmpty())
                cout << "Maximum: " << mx << "\n";
        } else if (choice == 3) {
            int mx = queue.extractMax();
            if (mx != -1 || !queue.isEmpty())
                cout << "Extracted: " << mx << "\n";
        } else if (choice == 4) {
            cout << "Priority queue elements:\n";
            queue.show();
        } else {
            cout << "Invalid choice\n";
        }
    }

    cout << "Exiting.\n";
    return 0;
}
