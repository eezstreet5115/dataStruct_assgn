#include <iostream>
using namespace std;

int main() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    int i = 0, j = 0;
    while (str1[i] != '\0') i++; // move to end of str1
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++; j++;
    }
    str1[i] = '\0'; // terminate

    cout << "Concatenated string: " << str1 << "\n";
    return 0;
}
