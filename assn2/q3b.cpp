#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2; // because array has n-1 elements
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1) {
            // left side is perfect, search right
            low = mid + 1;
        } else {
            // missing number is here or before
            high = mid - 1;
        }
    }
    return low + 1; // missing number
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; // n=6, missing=4
    int n = 6;

    cout << "Missing number (Binary Search): " << findMissingBinary(arr, n) << "\n";

    return 0;
}
