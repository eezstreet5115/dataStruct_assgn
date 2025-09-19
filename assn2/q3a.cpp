#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1; // missing number found
        }
    }
    return n; // if all are correct, missing is last number
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; // n=6, missing=4
    int n = 6;

    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << "\n";

    return 0;
}
