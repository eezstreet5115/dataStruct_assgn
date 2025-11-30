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

struct BinaryTree {
    TreeNode* root;

    BinaryTree() {
        root = NULL;
    }

    TreeNode* insertNode(TreeNode* current, int newValue) {
        if (!current) {
            TreeNode* newNode = new TreeNode(newValue);
            return newNode;
        }
        if (newValue < current->value)
            current->left = insertNode(current->left, newValue);
        else if (newValue > current->value)
            current->right = insertNode(current->right, newValue);
        return current;
    }

    void insert(int newValue) {
        root = insertNode(root, newValue);
    }

    bool isBSTUtil(TreeNode* current, long long minValue, long long maxValue) {
        if (!current) return true;
        if (current->value <= minValue || current->value >= maxValue)
            return false;
        return isBSTUtil(current->left, minValue, current->value) &&
               isBSTUtil(current->right, current->value, maxValue);
    }

    bool isBST() {
        long long minLimit = -1000000000000LL;
        long long maxLimit = 1000000000000LL;
        return isBSTUtil(root, minLimit, maxLimit);
    }

    void inOrder(TreeNode* current) {
        if (!current) return;
        inOrder(current->left);
        cout << current->value << " ";
        inOrder(current->right);
    }
};

int main() {
    BinaryTree tree;
    int total;
    cout << "Enter number of nodes to insert: ";
    cin >> total;

    for (int i = 0; i < total; i++) {
        int value;
        cout << "Value " << (i + 1) << ": ";
        cin >> value;
        tree.insert(value);
    }

    cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    cout << "\n";

    if (tree.isBST())
        cout << "Tree IS a BST\n";
    else
        cout << "Tree is NOT a BST\n";

    return 0;
}
