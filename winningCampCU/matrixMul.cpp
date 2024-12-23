#include <bits/stdc++.h>
using namespace std;

class MatrixOperations {
public:
    void operate(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        int rows = A.size();
        int cols = A[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = A[i][j] + B[i][j];
            }
        }
        displayMatrix(result);
    }

    void operate(vector<vector<int>>& A, vector<vector<int>>& B, int) {
        int rows = A.size();
        int cols = B[0].size();
        int commonDim = B.size();
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (int k = 0; k < commonDim; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        displayMatrix(result);
    }

    void displayMatrix(vector<vector<int>>& matrix) {
        for (const auto& row : matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    MatrixOperations mtrxOps;

    int rowsA, colsA, rowsB, colsB;
    cout << "Enter rows and columns for Matrix A: ";
    cin >> rowsA >> colsA;
    vector<vector<int>> A(rowsA, vector<int>(colsA));
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Enter rows and columns for Matrix B: ";
    cin >> rowsB >> colsB;
    vector<vector<int>> B(rowsB, vector<int>(colsB));
    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            cin >> B[i][j];
        }
    }

    if (rowsA == rowsB && colsA == colsB) {
        cout << "Matrix Addition Result:\n";
        mtrxOps.operate(A, B);
    } else {
        cout << "Matrix addition is not possible.\n";
    }

    if (colsA == rowsB) {
        cout << "Matrix Multiplication Result:\n";
        mtrxOps.operate(A, B, 0);
    } else {
        cout << "First Matrix Columns to be equal to rows of second matrix in no.\n";
    }
    return 0;
}