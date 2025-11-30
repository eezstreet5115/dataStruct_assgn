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
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;
    cout << "Enter size of second array: ";
    cin >> m;

    int* a = new int[n];
    int* b = new int[m];

    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "]: ";
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cout << "B[" << i << "]: ";
        cin >> b[i];
    }

    SetNode* setA[TABLE_SIZE];
    SetNode* printed[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        setA[i] = NULL;
        printed[i] = NULL;
    }

    for (int i = 0; i < n; i++)
        setInsert(setA, a[i]);

    cout << "Common elements: ";
    bool firstPrint = true;
    for (int i = 0; i < m; i++) {
        if (setContains(setA, b[i]) && !setContains(printed, b[i])) {
            if (!firstPrint) cout << " ";
            cout << b[i];
            firstPrint = false;
            setInsert(printed, b[i]);
        }
    }
    cout << "\n";

    clearSet(setA);
    clearSet(printed);
    delete[] a;
    delete[] b;
    return 0;
}
