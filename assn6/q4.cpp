#include <iostream>
using namespace std;

struct CharacterNode {
    char value;
    CharacterNode* previous;
    CharacterNode* next;

    CharacterNode(char c = 0) {
        value = c;
        previous = NULL;
        next = NULL;
    }
};

struct CharacterDoublyList {
    CharacterNode* first;

    CharacterDoublyList() {
        first = NULL;
    }

    void addAtEnd(char value) {
        CharacterNode* newNode = new CharacterNode(value);

        if (!first) {
            first = newNode;
            return;
        }

        CharacterNode* temp = first;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
        newNode->previous = temp;
    }

    bool checkPalindrome() {
        if (!first) return true;

        CharacterNode* left = first;
        CharacterNode* right = first;

        while (right->next)
            right = right->next;

        while (left != right && left->previous != right) {
            if (left->value != right->value)
                return false;

            left = left->next;
            right = right->previous;
        }

        return true;
    }

    void show() {
        if (!first) {
            cout << "(empty)\n";
            return;
        }

        CharacterNode* temp = first;
        while (temp) {
            cout << temp->value;
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    CharacterDoublyList list;
    int totalCharacters;

    cout << "Enter number of characters: ";
    cin >> totalCharacters;

    for (int i = 0; i < totalCharacters; i++) {
        char character;
        cout << "Char " << (i + 1) << ": ";
        cin >> character;
        list.addAtEnd(character);
    }

    cout << "List: ";
    list.show();

    cout << (list.checkPalindrome() ? "Palindrome\n" : "Not Palindrome\n");
    return 0;
}
