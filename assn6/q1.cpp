#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* previous;
    Node* next;

    Node(int v = 0) {
        value = v;
        previous = NULL;
        next = NULL;
    }
};

struct DoublyList {
    Node* first;

    DoublyList() {
        first = NULL;
    }

    void show() {
        if (!first) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = first;
        while (temp) {
            cout << temp->value;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << "\n";
    }

    int length() {
        int count = 0;
        Node* temp = first;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void addAtStart(int value) {
        Node* newNode = new Node(value);
        if (!first) {
            first = newNode;
            return;
        }

        newNode->next = first;
        first->previous = newNode;
        first = newNode;
    }

    void addAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!first) {
            first = newNode;
            return;
        }

        Node* temp = first;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
        newNode->previous = temp;
    }

    bool addAfter(int target, int value) {
        Node* temp = first;

        while (temp && temp->value != target)
            temp = temp->next;

        if (!temp) return false;

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        newNode->previous = temp;

        if (temp->next)
            temp->next->previous = newNode;

        temp->next = newNode;
        return true;
    }

    bool addBefore(int target, int value) {
        Node* temp = first;

        while (temp && temp->value != target)
            temp = temp->next;

        if (!temp) return false;

        Node* newNode = new Node(value);
        newNode->next = temp;
        newNode->previous = temp->previous;

        if (temp->previous)
            temp->previous->next = newNode;
        else
            first = newNode;

        temp->previous = newNode;
        return true;
    }

    bool removeValue(int target) {
        Node* temp = first;

        while (temp && temp->value != target)
            temp = temp->next;

        if (!temp) return false;

        if (temp->previous)
            temp->previous->next = temp->next;
        else
            first = temp->next;

        if (temp->next)
            temp->next->previous = temp->previous;

        delete temp;
        return true;
    }

    bool find(int target) {
        Node* temp = first;
        while (temp) {
            if (temp->value == target)
                return true;
            temp = temp->next;
        }
        return false;
    }
};

int main() {
    DoublyList list;
    int choice;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after value\n";
        cout << "4. Insert before value\n";
        cout << "5. Delete value\n";
        cout << "6. Search\n";
        cout << "7. Display\n";
        cout << "8. Size\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            list.addAtStart(value);
        }
        else if (choice == 2) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            list.addAtEnd(value);
        }
        else if (choice == 3) {
            int target, value;
            cout << "Enter target: ";
            cin >> target;
            cout << "Enter value: ";
            cin >> value;

            if (!list.addAfter(target, value))
                cout << "Target not found\n";
        }
        else if (choice == 4) {
            int target, value;
            cout << "Enter target: ";
            cin >> target;
            cout << "Enter value: ";
            cin >> value;

            if (!list.addBefore(target, value))
                cout << "Target not found\n";
        }
        else if (choice == 5) {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;

            if (list.removeValue(value))
                cout << "Deleted\n";
            else
                cout << "Not found\n";
        }
        else if (choice == 6) {
            int value;
            cout << "Enter value to search: ";
            cin >> value;

            if (list.find(value))
                cout << "Found\n";
            else
                cout << "Not found\n";
        }
        else if (choice == 7) {
            list.show();
        }
        else if (choice == 8) {
            cout << "Size: " << list.length() << "\n";
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    cout << "Program exited.\n";
    return 0;
}
