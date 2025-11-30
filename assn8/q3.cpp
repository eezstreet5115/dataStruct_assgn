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

struct BinarySearchTree {
    TreeNode* root;

    BinarySearchTree() {
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

    TreeNode* findMin(TreeNode* current) {
        if (!current) return NULL;
        while (current->left)
            current = current->left;
        return current;
    }

    TreeNode* deleteNode(TreeNode* current, int target) {
        if (!current) return NULL;

        if (target < current->value) {
            current->left = deleteNode(current->left, target);
        } else if (target > current->value) {
            current->right = deleteNode(current->right, target);
        } else {
            if (!current->left && !current->right) {
                delete current;
                return NULL;
            } else if (!current->left) {
                TreeNode* temp = current->right;
                delete current;
                return temp;
            } else if (!current->right) {
                TreeNode* temp = current->left;
                delete current;
                return temp;
            } else {
                TreeNode* successor = findMin(current->right);
                current->value = successor->value;
                current->right = deleteNode(current->right, successor->value);
            }
        }
        return current;
    }

    void remove(int target) {
        root = deleteNode(root, target);
    }

    int maxDepth(TreeNode* current) {
        if (!current) return 0;
        int leftDepth = maxDepth(current->left);
        int rightDepth = maxDepth(current->right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }

    int minDepth(TreeNode* current) {
        if (!current) return 0;
        int leftDepth = minDepth(current->left);
        int rightDepth = minDepth(current->right);

        if (!current->left && !current->right) return 1;
        if (!current->left) return rightDepth + 1;
        if (!current->right) return leftDepth + 1;

        return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
    }

    void inOrder(TreeNode* current) {
        if (!current) return;
        inOrder(current->left);
        cout << current->value << " ";
        inOrder(current->right);
    }
};

int main() {
    BinarySearchTree tree;
    int choice;

    while (true) {
        cout << "\n--- BST Insert/Delete/Depth Menu ---\n";
        cout << "1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. In-order traversal\n";
        cout << "4. Maximum depth\n";
        cout << "5. Minimum depth\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
        } else if (choice == 2) {
            int target;
            cout << "Enter value to delete: ";
            cin >> target;
            tree.remove(target);
        } else if (choice == 3) {
            cout << "In-order: ";
            tree.inOrder(tree.root);
            cout << "\n";
        } else if (choice == 4) {
            cout << "Maximum depth: " << tree.maxDepth(tree.root) << "\n";
        } else if (choice == 5) {
            cout << "Minimum depth: " << tree.minDepth(tree.root) << "\n";
        } else {
            cout << "Invalid choice\n";
        }
    }

    cout << "Exiting.\n";
    return 0;
}
