#include <iostream>
using namespace std;

const int TABLE_SIZE = 101;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

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

TreeNode* createNode(int value) {
    TreeNode* node = new TreeNode;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insertAsBinaryTree(TreeNode* root, int value) {
    if (!root) return createNode(value);

    int choice;
    cout << "Insert " << value << " as left(1) or right(2) child while traversing? ";
    cout << "(Current node value: " << root->value << "): ";
    cin >> choice;

    if (choice == 1)
        root->left = insertAsBinaryTree(root->left, value);
    else
        root->right = insertAsBinaryTree(root->right, value);

    return root;
}

bool checkDuplicates(TreeNode* root, SetNode* table[]) {
    if (!root) return false;
    if (setContains(table, root->value))
        return true;
    setInsert(table, root->value);
    if (checkDuplicates(root->left, table)) return true;
    if (checkDuplicates(root->right, table)) return true;
    return false;
}

void clearTree(TreeNode* root) {
    if (!root) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

int main() {
    int n;
    cout << "Enter number of nodes in binary tree: ";
    cin >> n;

    if (n <= 0) {
        cout << "No Duplicates\n";
        return 0;
    }

    TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Node value " << (i + 1) << ": ";
        cin >> value;
        if (!root)
            root = createNode(value);
        else
            root = insertAsBinaryTree(root, value);
    }

    SetNode* table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;

    bool hasDuplicates = checkDuplicates(root, table);

    if (hasDuplicates)
        cout << "Duplicates Found\n";
    else
        cout << "No Duplicates\n";

    clearSet(table);
    clearTree(root);
    return 0;
}
