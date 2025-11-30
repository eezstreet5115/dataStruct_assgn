#include <iostream>
using namespace std;

void swapValues(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

void copyArray(int original[], int copy[], int size) {
    for (int i = 0; i < size; i++)
        copy[i] = original[i];
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

void selectionSort(int numbers[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (numbers[j] < numbers[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            swapValues(numbers[i], numbers[minIndex]);
    }
}

void insertionSort(int numbers[], int size) {
    for (int i = 1; i < size; i++) {
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = key;
    }
}

void bubbleSort(int numbers[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swapValues(numbers[j], numbers[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void mergeParts(int numbers[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int *leftPart = new int[leftSize];
    int *rightPart = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftPart[i] = numbers[left + i];
    for (int j = 0; j < rightSize; j++)
        rightPart[j] = numbers[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if (leftPart[i] <= rightPart[j]) {
            numbers[k] = leftPart[i];
            i++;
        } else {
            numbers[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        numbers[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        numbers[k] = rightPart[j];
        j++;
        k++;
    }

    delete[] leftPart;
    delete[] rightPart;
}

void mergeSort(int numbers[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(numbers, left, mid);
    mergeSort(numbers, mid + 1, right);
    mergeParts(numbers, left, mid, right);
}

int partitionArray(int numbers[], int left, int right) {
    int pivot = numbers[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (numbers[j] <= pivot) {
            i++;
            swapValues(numbers[i], numbers[j]);
        }
    }
    swapValues(numbers[i + 1], numbers[right]);
    return i + 1;
}

void quickSort(int numbers[], int left, int right) {
    if (left >= right) return;
    int pivotIndex = partitionArray(numbers, left, right);
    quickSort(numbers, left, pivotIndex - 1);
    quickSort(numbers, pivotIndex + 1, right);
}

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    if (size <= 0) {
        cout << "No elements to sort.\n";
        return 0;
    }

    int *original = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Value " << (i + 1) << ": ";
        cin >> original[i];
    }

    int choice;

    while (true) {
        cout << "\n--- Sorting Menu ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Show Original Array\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice >= 1 && choice <= 5) {
            int *working = new int[size];
            copyArray(original, working, size);

            if (choice == 1) {
                selectionSort(working, size);
                cout << "Array after Selection Sort:\n";
            } else if (choice == 2) {
                insertionSort(working, size);
                cout << "Array after Insertion Sort:\n";
            } else if (choice == 3) {
                bubbleSort(working, size);
                cout << "Array after Bubble Sort:\n";
            } else if (choice == 4) {
                mergeSort(working, 0, size - 1);
                cout << "Array after Merge Sort:\n";
            } else if (choice == 5) {
                quickSort(working, 0, size - 1);
                cout << "Array after Quick Sort:\n";
            }

            showArray(working, size);
            delete[] working;
        } else if (choice == 6) {
            cout << "Original array:\n";
            showArray(original, size);
        } else {
            cout << "Invalid choice\n";
        }
    }

    delete[] original;
    cout << "Exiting.\n";
    return 0;
}
