#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int v = 0) {
        value = v;
        next = NULL;
    }
};

struct CircularLinkedList {
    Node* headNode;

    CircularLinkedList() {
        headNode = NULL;
    }

    void displayWithHeadRepeatedAtEnd() {
        if (!headNode) {
            cout << "List is empty\n";
            return;
        }

        Node* currentNode = headNode;
        bool isFirst = true;

        do {
            if (!isFirst) cout << " ";
            cout << currentNode->value;
            currentNode = currentNode->next;
            isFirst = false;
        } while (currentNode != headNode);

        cout << " " << headNode->value << "\n";
    }

    int length() {
        if (!headNode) return 0;

        int count = 0;
        Node* currentNode = headNode;

        do {
            count++;
            currentNode = currentNode->next;
        } while (currentNode != headNode);

        return count;
    }

    void addAtStart(int newValue) {
        Node* newNode = new Node(newValue);

        if (!headNode) {
            headNode = newNode;
            newNode->next = newNode;
            return;
        }

        Node* currentNode = headNode;
        while (currentNode->next != headNode)
            currentNode = currentNode->next;

        newNode->next = headNode;
        currentNode->next = newNode;
        headNode = newNode;
    }

    void addAtEnd(int newValue) {
        Node* newNode = new Node(newValue);

        if (!headNode) {
            headNode = newNode;
            newNode->next = newNode;
            return;
        }

        Node* currentNode = headNode;
        while (currentNode->next != headNode)
            currentNode = currentNode->next;

        currentNode->next = newNode;
        newNode->next = headNode;
    }

    bool addAfter(int targetValue, int newValue) {
        if (!headNode) return false;

        Node* currentNode = headNode;

        do {
            if (currentNode->value == targetValue) {
                Node* newNode = new Node(newValue);
                newNode->next = currentNode->next;
                currentNode->next = newNode;
                return true;
            }
            currentNode = currentNode->next;
        } while (currentNode != headNode);

        return false;
    }

    bool addBefore(int targetValue, int newValue) {
        if (!headNode) return false;

        Node* currentNode = headNode;
        Node* previousNode = NULL;

        do {
            if (currentNode->value == targetValue) break;
            previousNode = currentNode;
            currentNode = currentNode->next;
        } while (currentNode != headNode);

        if (currentNode->value != targetValue) return false;

        if (currentNode == headNode) {
            addAtStart(newValue);
            return true;
        } else {
            Node* newNode = new Node(newValue);
            previousNode->next = newNode;
            newNode->next = currentNode;
            return true;
        }
    }

    bool removeValue(int targetValue) {
        if (!headNode) return false;

        Node* currentNode = headNode;
        Node* previousNode = NULL;

        do {
            if (currentNode->value == targetValue) break;
            previousNode = currentNode;
            currentNode = currentNode->next;
        } while (currentNode != headNode);

        if (currentNode->value != targetValue) return false;

        if (currentNode == headNode) {
            if (headNode->next == headNode) {
                delete headNode;
                headNode = NULL;
                return true;
            }

            Node* tailNode = headNode;
            while (tailNode->next != headNode)
                tailNode = tailNode->next;

            tailNode->next = headNode->next;
            Node* nodeToDelete = headNode;
            headNode = headNode->next;
            delete nodeToDelete;
            return true;
        } else {
            previousNode->next = currentNode->next;
            delete currentNode;
            return true;
        }
    }

    bool find(int targetValue) {
        if (!headNode) return false;

        Node* currentNode = headNode;
        do {
            if (currentNode->value == targetValue)
                return true;
            currentNode = currentNode->next;
        } while (currentNode != headNode);

        return false;
    }
};

int main() {
    CircularLinkedList list;
    int choice;

    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1.Insert at beginning\n";
        cout << "2.Insert at end\n";
        cout << "3.Insert after value\n";
        cout << "4.Insert before value\n";
        cout << "5.Delete value\n";
        cout << "6.Search\n";
        cout << "7.Display (repeat head at end)\n";
        cout << "8.Size\n";
        cout << "0.Exit\n";
        cout << "Choice: ";

        cin >> choice;
        if (choice == 0) break;

        if (choice == 1) {
            int value;
            cout << "Value: ";
            cin >> value;
            list.addAtStart(value);
        }
        else if (choice == 2) {
            int value;
            cout << "Value: ";
            cin >> value;
            list.addAtEnd(value);
        }
        else if (choice == 3) {
            int target, value;
            cout << "Target: ";
            cin >> target;
            cout << "Value: ";
            cin >> value;
            if (!list.addAfter(target, value))
                cout << "Target not found\n";
        }
        else if (choice == 4) {
            int target, value;
            cout << "Target: ";
            cin >> target;
            cout << "Value: ";
            cin >> value;
            if (!list.addBefore(target, value))
                cout << "Target not found\n";
        }
        else if (choice == 5) {
            int target;
            cout << "Value to delete: ";
            cin >> target;
            cout << (list.removeValue(target) ? "Deleted\n" : "Not found\n");
        }
        else if (choice == 6) {
            int target;
            cout << "Search value: ";
            cin >> target;
            cout << (list.find(target) ? "Found\n" : "Not found\n");
        }
        else if (choice == 7) {
            list.displayWithHeadRepeatedAtEnd();
        }
        else if (choice == 8) {
            cout << "Size: " << list.length() << "\n";
        }
        else {
            cout << "Invalid\n";
        }
    }

    cout << "Exiting.\n";
    return 0;
}
