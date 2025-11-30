#include <iostream>
using namespace std;

const int TABLE_SIZE = 101;

struct MapNode {
    int key;
    int count;
    MapNode* next;
};

int hashValue(int x) {
    int h = x % TABLE_SIZE;
    if (h < 0) h += TABLE_SIZE;
    return h;
}

void mapIncrement(MapNode* table[], int key) {
    int index = hashValue(key);
    MapNode* current = table[index];
    while (current) {
        if (current->key == key) {
            current->count++;
            return;
        }
        current = current->next;
    }
    MapNode* node = new MapNode;
    node->key = key;
    node->count = 1;
    node->next = table[index];
    table[index] = node;
}

int mapGetCount(MapNode* table[], int key) {
    int index = hashValue(key);
    MapNode* current = table[index];
    while (current) {
        if (current->key == key)
            return current->count;
        current = current->next;
    }
    return 0;
}

void clearMap(MapNode* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        MapNode* current = table[i];
        while (current) {
            MapNode* temp = current;
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

    MapNode* table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;

    for (int i = 0; i < n; i++)
        mapIncrement(table, nums[i]);

    bool found = false;
    int answer = -1;

    for (int i = 0; i < n; i++) {
        if (mapGetCount(table, nums[i]) == 1) {
            found = true;
            answer = nums[i];
            break;
        }
    }

    if (found)
        cout << answer << "\n";
    else
        cout << "No non-repeating element\n";

    clearMap(table);
    delete[] nums;
    return 0;
}
