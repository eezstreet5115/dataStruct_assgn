#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v = 0) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertInBST(TreeNode* current, int newValue) {
    if (!current) {
        TreeNode* newNode = new TreeNode(newValue);
        return newNode;
    }
    if (newValue < current->value)
        current->left = insertInBST(current->left, newValue);
    else if (newValue > current->value)
        current->right = insertInBST(current->right, newValue);
    return current;
}

void preOrder(TreeNode* current) {
    if (!current) return;
    cout << current->value << " ";
    preOrder(current->left);
    preOrder(current->right);
}

void inOrder(TreeNode* current) {
    if (!current) return;
    inOrder(current->left);
    cout << current->value << " ";
    inOrder(current->right);
}

void postOrder(TreeNode* current) {
    if (!current) return;
    postOrder(current->left);
    postOrder(current->right);
    cout << current->value << " ";
}

int main() {
    TreeNode* root = NULL;
    int total;
    cout << "Enter number of nodes: ";
    cin >> total;

    for (int i = 0; i < total; i++) {
        int value;
        cout << "Value " << (i + 1) << ": ";
        cin >> value;
        root = insertInBST(root, value);
    }

    cout << "Pre-order: ";
    preOrder(root);
    cout << "\n";

    cout << "In-order: ";
    inOrder(root);
    cout << "\n";

    cout << "Post-order: ";
    postOrder(root);
    cout << "\n";

    return 0;
}
