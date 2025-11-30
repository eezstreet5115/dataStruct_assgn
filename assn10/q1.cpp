#include <iostream>
using namespace std;

const int TABLE_SIZE = 101;

struct SetNode {
    int value;
    SetNode* next;
};

int hashValue(int x) {
    int h = x % TABLE_SIZE;
    if (h < 0) h += TABLE_SIZE;
    return h;
}

bool setContains(SetNode* table[], int value) {
    int index = hashValue(value);
    SetNode* current = table[index];
    while (current) {
        if (current->value == value) return true;
        current = current->next;
    }
    return false;
}

void setInsert(SetNode* table[], int value) {
    if (setContains(table, value)) return;
    int index = hashValue(value);
    SetNode* node = new SetNode;
    node->value = value;
    node->next = table[index];
    table[index] = node;
}

void clearSet(SetNode* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        SetNode* current = table[i];
        while (current) {
            SetNode* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = NULL;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* nums = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Value " << (i + 1) << ": ";
        cin >> nums[i];
    }

    SetNode* table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;

    bool hasDuplicate = false;
    for (int i = 0; i < n; i++) {
        if (setContains(table, nums[i])) {
            hasDuplicate = true;
            break;
        }
        setInsert(table, nums[i]);
    }

    cout << (hasDuplicate ? "true\n" : "false\n");

    clearSet(table);
    delete[] nums;
    return 0;
}
