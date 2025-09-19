#include <iostream>
using namespace std;

int main() {
    int arr[10][10], row, col;

    cout << "Enter number of rows and columns: ";
    cin >> row >> col;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    // row sums
    cout << "Sum of each row:\n";
    for (int i = 0; i < row; i++) {
        int rowSum = 0;
        for (int j = 0; j < col; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i << " = " << rowSum << "\n";
    }

    // col sums
    cout << "Sum of each column:\n";
    for (int j = 0; j < col; j++) {
        int colSum = 0;
        for (int i = 0; i < row; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j << " = " << colSum << "\n";
    }

    return 0;
}
