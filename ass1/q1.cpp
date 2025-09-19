#include <iostream>
using namespace std;

class ArrayOperations {
    int arr[100];   
    int size = 0;       

public:

    void create() {
        cout << "enter number of elements: ";
        cin >> size;
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty!!\n";
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void insertElement() {
        int pos, val;
        cout << "Enter position(index): ";
        cin >> pos;
        cout << "Enter value to insert: ";
        cin >> val;

        if (pos < 0 || pos > size || size >= 100) {
            cout << "Invalid position or array full!\n";
            return;
        }

        // shifting right
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        size++;
        cout << "Inserted successfully.\n";
    }

    void deleteElement() {
        int pos;
        cout << "Enter position(index): ";
        cin >> pos;

        if (pos < 0 || pos >= size) {
            cout << "Invalid position!\n";
            return;
        }

        // shifting left
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Deleted successfully.\n";
    }

    void linearSearch() {
        int key;
        cout << "Enter element to search: ";
        cin >> key;

        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                cout << "Element found at position " << i << "\n";
                return;
            }
        }
        cout << "Element not found.\n";
    }
};

int main() {
    ArrayOperations opr;
    int choice;
    do {
        cout << "\n——MENU——\n";
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: opr.create(); break;
            case 2: opr.display(); break;
            case 3: opr.insertElement(); break;
            case 4: opr.deleteElement(); break;
            case 5: opr.linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
