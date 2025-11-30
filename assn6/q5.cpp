#include <iostream>
using namespace std;

struct SingleNode {
    int value;
    SingleNode* next;

    SingleNode(int v = 0) {
        value = v;
        next = NULL;
    }
};

bool checkCircular(SingleNode* first) {
    if (!first) return false;

    SingleNode* slowPointer = first;
    SingleNode* fastPointer = first;

    while (fastPointer && fastPointer->next) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;

        if (slowPointer == fastPointer)
            return true;
    }

    return false;
}

int main() {
    int totalNodes;
    cout << "Build singly linked list. Enter number of nodes: ";
    cin >> totalNodes;

    if (totalNodes <= 0) {
        cout << "Empty list -> Not circular\n";
        return 0;
    }

    SingleNode* first = NULL;
    SingleNode* last = NULL;

    for (int i = 0; i < totalNodes; i++) {
        int value;
        cout << "Value " << (i + 1) << ": ";
        cin >> value;

        SingleNode* newNode = new SingleNode(value);

        if (!first)
            first = last = newNode;
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    cout << "Do you want to make a cycle? (1=yes, 0=no): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter position (1-based) to which last node should link (enter 0 to link to head): ";
        int position;
        cin >> position;

        SingleNode* target = first;

        if (position <= 0) {
            target = first;
        } else {
            int index = 1;
            while (target && index < position) {
                target = target->next;
                index++;
            }
            if (!target)
                target = first;
        }

        last->next = target;
        cout << "Cycle created.\n";
    }

    cout << (checkCircular(first) ? 
            "True: List is circular\n" : 
            "False: List is not circular\n");

    return 0;
}
