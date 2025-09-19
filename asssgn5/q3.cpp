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

    void findMiddle() {
        if (!head) { cout << "List is empty\n"; return; }
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle node: " << slow->data << endl;
    }

    void display() {
        for (Node* t = head; t; t = t->next)
            cout << t->data << (t->next ? "->" : "");
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

    cout << "Linked List: ";
    list.display();

    list.findMiddle();

    return 0;
}
