#include <iostream>
using namespace std;

const int TABLE_SIZE = 101;

struct Node {
    int value;
    Node* next;
};

struct PtrNode {
    void* address;
    PtrNode* next;
};

int hashPtr(void* p) {
    unsigned long long x = (unsigned long long)p;
    x = x >> 3;
    return (int)(x % TABLE_SIZE);
}

bool setContainsPtr(PtrNode* table[], void* ptr) {
    int index = hashPtr(ptr);
    PtrNode* current = table[index];
    while (current) {
        if (current->address == ptr) return true;
        current = current->next;
    }
    return false;
}

void setInsertPtr(PtrNode* table[], void* ptr) {
    if (setContainsPtr(table, ptr)) return;
    int index = hashPtr(ptr);
    PtrNode* node = new PtrNode;
    node->address = ptr;
    node->next = table[index];
    table[index] = node;
}

void clearPtrSet(PtrNode* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        PtrNode* current = table[i];
        while (current) {
            PtrNode* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = NULL;
    }
}

int main() {
    int n;
    cout << "Enter number of nodes in linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "List is empty\n";
        return 0;
    }

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Value " << (i + 1) << ": ";
        cin >> value;
        Node* node = new Node;
        node->value = value;
        node->next = NULL;

        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    cout << "Do you want to create a loop? (1=yes, 0=no): ";
    int createLoop;
    cin >> createLoop;

    if (createLoop == 1) {
        cout << "Enter position (1-based) to link last node to (0 for head): ";
        int pos;
        cin >> pos;
        Node* target = head;
        if (pos <= 0) target = head;
        else {
            int index = 1;
            while (target && index < pos) {
                target = target->next;
                index++;
            }
            if (!target) target = head;
        }
        tail->next = target;
    }

    PtrNode* visited[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) visited[i] = NULL;

    bool hasLoop = false;
    Node* current = head;
    while (current) {
        if (setContainsPtr(visited, current)) {
            hasLoop = true;
            break;
        }
        setInsertPtr(visited, current);
        current = current->next;
    }

    cout << (hasLoop ? "true\n" : "false\n");

    clearPtrSet(visited);

    if (!hasLoop) {
        current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}
