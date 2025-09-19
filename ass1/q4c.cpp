#include <iostream>
using namespace std;

int main() {
    int A[10][10], T[10][10];
    int m, n;

    cout << "Enter rows and cols of Matrix: ";
    cin >> m >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            T[j][i] = A[i][j];           // transpose
        }
    }

    cout << "Transpose Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << T[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
