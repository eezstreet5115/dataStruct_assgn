#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;          // found at index mid
        else if (arr[mid] < key)
            low = mid + 1;       // search right half
        else
            high = mid - 1;      // search left half
    }
    return -1;   // not found
}

int main() {
    int arr[100], n, key;

    cout << "Enter number of elements (sorted): ";
    cin >> n;

    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << "\n";
    else
        cout << "Element not found.\n";

    return 0;
}
