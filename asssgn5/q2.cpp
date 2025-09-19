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

    int countOccurrences(int key) {
        int count = 0;
        for (Node* t = head; t; t = t->next)
            if (t->data == key) count++;
        return count;
    }

    void deleteAllOccurrences(int key) {
        while (head && head->data == key) {  // delete from beginning
            Node* t = head;
            head = head->next;
            delete t;
        }
        Node* t = head;
        while (t && t->next) {
            if (t->next->data == key) {
                Node* temp = t->next;
                t->next = t->next->next;
                delete temp;
            } else t = t->next;
        }
    }

    void display() {
        for (Node* t = head; t; t = t->next)
            cout << t->data << (t->next ? "->" : "");
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int n, val, key;
    
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) { cin >> val; list.insertAtEnd(val); }

    cout << "Enter key to count and delete: ";
    cin >> key;

    int count = list.countOccurrences(key);
    cout << "Count: " << count << endl;

    list.deleteAllOccurrences(key);

    cout << "Updated Linked List: ";
    list.display();

    return 0;
}
