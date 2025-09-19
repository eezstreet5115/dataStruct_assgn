#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head = nullptr;
public:
    void insertAtEnd(int val) {
        Node* n = new Node{val, nullptr};
        if (!head) head = n;
        else {
            Node* t = head;
            while (t->next) t = t->next;
            t->next = n;
        }
    }

    void reverse() {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() {
        for (Node* t = head; t; t = t->next)
            cout << t->data << (t->next ? "->" : "->NULL");
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) { cin >> val; list.insertAtEnd(val); }

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
