#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        int isDistinct = 1; // assume current element is distinct
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = 0; // found duplicate
                break;
            }
        }
        if (isDistinct == 1) distinctCount++;
    }

    cout << "Total number of distinct elements: " << distinctCount << "\n";
    return 0;
}
