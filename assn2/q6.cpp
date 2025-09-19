#include <iostream>
using namespace std;

//read sparse matrix
void readSparse(int mat[20][3]) {
    int rows, cols, nz;
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> rows >> cols >> nz;

    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = nz;

    cout << "Enter row, col, value for " << nz << " non-zero elements:\n";
    for (int i = 1; i <= nz; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}

void displaySparse(int mat[20][3]) {
    int nz = mat[0][2];
    cout << "Row\tCol\tVal\n";
    for (int i = 0; i <= nz; i++) {
        cout << mat[i][0] << "\t" << mat[i][1] << "\t" << mat[i][2] << "\n";
    }
}
void transposeSparse(int mat[20][3], int result[20][3]) {
    int rows = mat[0][0], cols = mat[0][1], nz = mat[0][2];
    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = nz;

    int k = 1;
    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= nz; i++) {
            if (mat[i][1] == c) {
                result[k][0] = mat[i][1];
                result[k][1] = mat[i][0];
                result[k][2] = mat[i][2];
                k++;
            }
        }
    }
}

void addSparse(int a[20][3], int b[20][3], int sum[20][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Matrices cannot be added!\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            i++; k++;
        } else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++; k++;
        } else {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
    }

    while (i <= a[0][2]) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++; k++;
    }

    while (j <= b[0][2]) {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1;
}

void multiplySparse(int a[20][3], int b[20][3], int result[20][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Matrices cannot be multiplied!\n";
        return;
    }

    //transpose B for easier multiplication
    int bt[20][3];
    transposeSparse(b, bt);

    result[0][0] = a[0][0];
    result[0][1] = b[0][1];
    int k = 1;

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= bt[0][2]; j++) {
            if (a[i][1] == bt[j][1]) {
                int row = a[i][0];
                int col = bt[j][0];
                int val = a[i][2] * bt[j][2];

                //check if element already exists
                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (result[x][0] == row && result[x][1] == col) {
                        result[x][2] += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    result[k][0] = row;
                    result[k][1] = col;
                    result[k][2] = val;
                    k++;
                }
            }
        }
    }
    result[0][2] = k - 1;
}

int main() {
    int a[20][3], b[20][3], res[20][3];
    int choice;
    do {
        cout << "\n--- Sparse Matrix Operations ---\n";
        cout << "1. Transpose\n";
        cout << "2. Addition\n";
        cout << "3. Multiplication\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                readSparse(a);
                transposeSparse(a, res);
                cout << "Transpose (Triplet form):\n";
                displaySparse(res);
                break;

            case 2:
                cout << "Enter first matrix:\n";
                readSparse(a);
                cout << "Enter second matrix:\n";
                readSparse(b);
                addSparse(a, b, res);
                cout << "Sum (Triplet form):\n";
                displaySparse(res);
                break;

            case 3:
                cout << "Enter first matrix:\n";
                readSparse(a);
                cout << "Enter second matrix:\n";
                readSparse(b);
                multiplySparse(a, b, res);
                cout << "Product (Triplet form):\n";
                displaySparse(res);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
