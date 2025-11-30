#include <iostream>
using namespace std;

void swapValues(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

void showArray(int numbers[], int size) {
    if (size <= 0) {
        cout << "Array is empty\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << numbers[i];
        if (i + 1 < size) cout << " ";
    }
    cout << "\n";
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

void minHeapify(int numbers[], int size, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && numbers[leftChild] < numbers[smallest])
        smallest = leftChild;

    if (rightChild < size && numbers[rightChild] < numbers[smallest])
        smallest = rightChild;

    if (smallest != index) {
        swapValues(numbers[index], numbers[smallest]);
        minHeapify(numbers, size, smallest);
    }
}

void buildMaxHeap(int numbers[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        maxHeapify(numbers, size, i);
}

void buildMinHeap(int numbers[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        minHeapify(numbers, size, i);
}

void heapSortIncreasing(int numbers[], int size) {
    buildMaxHeap(numbers, size);
    for (int i = size - 1; i >= 1; i--) {
        swapValues(numbers[0], numbers[i]);
        maxHeapify(numbers, i, 0);
    }
}

void heapSortDecreasing(int numbers[], int size) {
    buildMinHeap(numbers, size);
    for (int i = size - 1; i >= 1; i--) {
        swapValues(numbers[0], numbers[i]);
        minHeapify(numbers, i, 0);
    }
}

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    if (size <= 0) {
        cout << "No elements to sort.\n";
        return 0;
    }

    int* original = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Value " << (i + 1) << ": ";
        cin >> original[i];
    }

    int* incArray = new int[size];
    int* decArray = new int[size];

    for (int i = 0; i < size; i++) {
        incArray[i] = original[i];
        decArray[i] = original[i];
    }

    heapSortIncreasing(incArray, size);
    heapSortDecreasing(decArray, size);

    cout << "Heapsort (Increasing order):\n";
    showArray(incArray, size);

    cout << "Heapsort (Decreasing order):\n";
    showArray(decArray, size);

    delete[] original;
    delete[] incArray;
    delete[] decArray;

    return 0;
}
