#include <iostream>
#include <cstring> // for strcmp, strcpy
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    char str[10][100];

    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    // Bubble sort
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(str[j], str[j+1]) > 0) {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j+1]);
                strcpy(str[j+1], temp);
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << str[i] << "\n";
    }

    return 0;
}
