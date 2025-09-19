#include <iostream>                           //all parts merged into one file
using namespace std;

void diagonalMatrix() {
    int n;
    cout << "Enter order of diagonal matrix: ";
    cin >> n;
    int diag[100];

    cout << "Enter diagonal elements:\n";
    for (int i = 0; i < n; i++) cin >> diag[i];

    cout << "Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else cout << "0 ";
        }
        cout << "\n";
    }
}

void triDiagonalMatrix() {
    int n;
    cout << "Enter order of tri-diagonal matrix: ";
    cin >> n;
    int arr[3*100]; // enough space

    cout << "Enter non-zero elements (lower, main, upper diagonals):\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) cin >> arr[k++];  // lower diagonal
        cin >> arr[k++];             // main diagonal
        if (i < n-1) cin >> arr[k++]; // upper diagonal
    }

    cout << "Tri-diagonal Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << arr[k] << " ";
            else if (i == j+1) cout << arr[k-1] << " ";
            else if (i+1 == j) cout << arr[k+1] << " ";
            else cout << "0 ";
        }
        cout << "\n";
        k += 2; // skip main+upper each row
    }
}

void lowerTriangularMatrix() {
    int n;
    cout << "Enter order of lower triangular matrix: ";
    cin >> n;
    int size = n*(n+1)/2;
    int arr[1000];

    cout << "Enter lower triangular elements row-wise:\n";
    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[k++];
        }
    }

    cout << "Lower Triangular Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j <= i) cout << arr[(i*(i-1))/2 + (j-1)] << " ";
            else cout << "0 ";
        }
        cout << "\n";
    }
}

void upperTriangularMatrix() {
    int n;
    cout << "Enter order of upper triangular matrix: ";
    cin >> n;
    int size = n*(n+1)/2;
    int arr[1000];

    cout << "Enter upper triangular elements row-wise:\n";
    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> arr[k++];
        }
    }

    cout << "Upper Triangular Matrix:\n";
    k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= i) {
                cout << arr[k++] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

void symmetricMatrix() {
    int n;
    cout << "Enter order of symmetric matrix: ";
    cin >> n;
    int size = n*(n+1)/2;
    int arr[1000];

    cout << "Enter lower triangular elements row-wise:\n";
    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[k++];
        }
    }

    cout << "Symmetric Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j) cout << arr[(i*(i-1))/2 + (j-1)] << " ";
            else cout << arr[(j*(j-1))/2 + (i-1)] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Matrix Storage Menu ---\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-diagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: diagonalMatrix(); break;
            case 2: triDiagonalMatrix(); break;
            case 3: lowerTriangularMatrix(); break;
            case 4: upperTriangularMatrix(); break;
            case 5: symmetricMatrix(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
