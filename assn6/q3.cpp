#include <iostream>
using namespace std;

struct DoubleNode {
    int value;
    DoubleNode* previous;
    DoubleNode* next;

    DoubleNode(int v = 0) {
        value = v;
        previous = NULL;
        next = NULL;
    }
};

struct CircleNode {
    int value;
    CircleNode* next;

    CircleNode(int v = 0) {
        value = v;
        next = NULL;
    }
};

int getDoublyListSizeFromUser() {
    int totalNodes;
    cout << "Build DLL: enter number of nodes: ";
    cin >> totalNodes;

    DoubleNode* first = NULL;
    DoubleNode* last = NULL;

    for (int i = 0; i < totalNodes; i++) {
        int value;
        cout << "Value " << (i + 1) << ": ";
        cin >> value;

        DoubleNode* newNode = new DoubleNode(value);

        if (!first) {
            first = last = newNode;
        } else {
            last->next = newNode;
            newNode->previous = last;
            last = newNode;
        }
    }

    int count = 0;
    DoubleNode* temp = first;

    while (temp) {
        count++;
        temp = temp->next;
    }

    temp = first;
    while (temp) {
        DoubleNode* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    return count;
}

int getCircularListSizeFromUser() {
    int totalNodes;
    cout << "Build CLL: enter number of nodes: ";
    cin >> totalNodes;

    if (totalNodes <= 0) return 0;

    CircleNode* first = NULL;
    CircleNode* last = NULL;

    for (int i = 0; i < totalNodes; i++) {
        int value;
        cout << "Value " << (i + 1) << ": ";
        cin >> value;

        CircleNode* newNode = new CircleNode(value);

        if (!first) {
            first = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    last->next = first;

    int count = 0;
    CircleNode* temp = first;

    do {
        count++;
        temp = temp->next;
    } while (temp != first);

    last->next = NULL;

    temp = first;
    while (temp) {
        CircleNode* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    return count;
}

int main() {
    cout << "Question 3: Find sizes of DLL and CLL\n";

    int doublySize = getDoublyListSizeFromUser();
    cout << "Size of created DLL: " << doublySize << "\n";

    int circularSize = getCircularListSizeFromUser();
    cout << "Size of created CLL: " << circularSize << "\n";

    cout << "Done.\n";
    return 0;
}
