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

    TreeNode* searchRecursive(TreeNode* current, int target) {
        if (!current) return NULL;
        if (current->value == target) return current;
        if (target < current->value)
            return searchRecursive(current->left, target);
        else
            return searchRecursive(current->right, target);
    }

    TreeNode* searchIterative(int target) {
        TreeNode* current = root;
        while (current) {
            if (current->value == target) return current;
            if (target < current->value)
                current = current->left;
            else
                current = current->right;
        }
        return NULL;
    }

    TreeNode* findMin(TreeNode* current) {
        if (!current) return NULL;
        while (current->left)
            current = current->left;
        return current;
    }

    TreeNode* findMax(TreeNode* current) {
        if (!current) return NULL;
        while (current->right)
            current = current->right;
        return current;
    }

    TreeNode* findSuccessor(int target) {
        TreeNode* current = root;
        TreeNode* successor = NULL;

        while (current) {
            if (target < current->value) {
                successor = current;
                current = current->left;
            } else if (target > current->value) {
                current = current->right;
            } else {
                if (current->right)
                    successor = findMin(current->right);
                break;
            }
        }
        return successor;
    }

    TreeNode* findPredecessor(int target) {
        TreeNode* current = root;
        TreeNode* predecessor = NULL;

        while (current) {
            if (target > current->value) {
                predecessor = current;
                current = current->right;
            } else if (target < current->value) {
                current = current->left;
            } else {
                if (current->left)
                    predecessor = findMax(current->left);
                break;
            }
        }
        return predecessor;
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
        cout << "\n--- BST Operations Menu ---\n";
        cout << "1. Insert element\n";
        cout << "2. In-order traversal\n";
        cout << "3. Search (Recursive)\n";
        cout << "4. Search (Iterative)\n";
        cout << "5. Minimum element\n";
        cout << "6. Maximum element\n";
        cout << "7. In-order successor\n";
        cout << "8. In-order predecessor\n";
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
            cout << "In-order: ";
            tree.inOrder(tree.root);
            cout << "\n";
        } else if (choice == 3) {
            int target;
            cout << "Enter value to search (recursive): ";
            cin >> target;
            TreeNode* result = tree.searchRecursive(tree.root, target);
            cout << (result ? "Found\n" : "Not found\n");
        } else if (choice == 4) {
            int target;
            cout << "Enter value to search (iterative): ";
            cin >> target;
            TreeNode* result = tree.searchIterative(target);
            cout << (result ? "Found\n" : "Not found\n");
        } else if (choice == 5) {
            TreeNode* mn = tree.findMin(tree.root);
            if (mn) cout << "Minimum element: " << mn->value << "\n";
            else cout << "Tree is empty\n";
        } else if (choice == 6) {
            TreeNode* mx = tree.findMax(tree.root);
            if (mx) cout << "Maximum element: " << mx->value << "\n";
            else cout << "Tree is empty\n";
        } else if (choice == 7) {
            int target;
            cout << "Enter value to find successor: ";
            cin >> target;
            TreeNode* succ = tree.findSuccessor(target);
            if (succ) cout << "Successor: " << succ->value << "\n";
            else cout << "Successor not found\n";
        } else if (choice == 8) {
            int target;
            cout << "Enter value to find predecessor: ";
            cin >> target;
            TreeNode* pred = tree.findPredecessor(target);
            if (pred) cout << "Predecessor: " << pred->value << "\n";
            else cout << "Predecessor not found\n";
        } else {
            cout << "Invalid choice\n";
        }
    }

    cout << "Exiting.\n";
    return 0;
}
