#include <iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter an uppercase character: ";
    cin >> c;

    if (c >= 'A' && c <= 'Z') {
        c = c + 32; // convert to lowercase
    }

    cout << "Lowercase: " << c << "\n";
    return 0;
}
