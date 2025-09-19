#include <iostream>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    cout << "String without vowels: " << str << "\n";
    return 0;
}
