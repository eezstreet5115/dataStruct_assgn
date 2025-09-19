#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = nullptr; }

    // (a) Insertion at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at the beginning.\n";
    }

    // (b) Insertion at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << value << " inserted at the end.\n";
    }

    // (c) Insertion before/after a specific node
    void insertBeforeAfter(int target, int value, bool before) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        // Insertion before head
        if (before && head->data == target) {
            newNode->next = head;
            head = newNode;
            cout << value << " inserted before " << target << ".\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != target) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << target << " not found.\n";
            delete newNode;
            return;
        }

        if (before) {
            newNode->next = temp;
            prev->next = newNode;
            cout << value << " inserted before " << target << ".\n";
        } else { // after
            newNode->next = temp->next;
            temp->next = newNode;
            cout << value << " inserted after " << target << ".\n";
        }
    }

    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) { // only one node
            cout << "Deleted " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        cout << "Deleted " << temp->data << " from end.\n";
        delete temp;
    }

    // (f) Deletion of a specific node
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted " << value << ".\n";
            delete temp;
            return;
        }
        Node* temp = head->next;
        Node* prev = head;
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << value << " not found.\n";
            return;
        }
        prev->next = temp->next;
        cout << "Deleted " << value << ".\n";
        delete temp;
    }

    // (g) Search for a node and display position
    void searchNode(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << value << " not found in the list.\n";
    }

    // (h) Display all nodes
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, target;
    bool before;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert before/after a node\n";
        cout << "4. Delete from beginning\n5. Delete from end\n6. Delete specific node\n";
        cout << "7. Search for a node\n8. Display list\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter target node value: ";
            cin >> target;
            cout << "Enter new value to insert: ";
            cin >> value;
            cout << "Insert before(1) or after(0)? ";
            cin >> before;
            list.insertBeforeAfter(target, value, before);
            break;
        case 4:
            list.deleteFromBeginning();
            break;
        case 5:
            list.deleteFromEnd();
            break;
        case 6:
            cout << "Enter node value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            list.searchNode(value);
            break;
        case 8:
            list.displayList();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}