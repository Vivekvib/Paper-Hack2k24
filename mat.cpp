#include <iostream>

using namespace std;

class Matrix {
private:
    int rows, cols;
    int **data;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Function to input matrix elements
    void input() {
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    // Function to display matrix elements
    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // Function to perform matrix addition
    Matrix add(Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Error: Incompatible matrix dimensions for addition\n";
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    // Function to perform matrix subtraction
    Matrix subtract(Matrix &other) {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Error: Incompatible matrix dimensions for subtraction\n";
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    // Function to perform matrix multiplication
    Matrix multiply(Matrix &other) {
        if (cols != other.rows) {
            cerr << "Error: Incompatible matrix dimensions for multiplication\n";
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }
};

int main() {
    int m, n, p, q;
    cout << "Enter dimensions of first matrix (m x n): ";
    cin >> m >> n;
    cout << "Enter dimensions of second matrix (p x q): ";
    cin >> p >> q;

    Matrix A(m, n), B(p, q), result(0, 0);
    int choice;

    cout << "Enter elements of first matrix:\n";
    A.input();
    cout << "Enter elements of second matrix:\n";
    B.input();

    cout << "1. Add matrices\n";
    cout << "2. Subtract matrices\n";
    cout << "3. Multiply matrices\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            result = A.add(B);
            cout << "Result of addition:\n";
            result.display();
            break;
        case 2:
            result = A.subtract(B);
            cout << "Result of subtraction:\n";
            result.display();
            break;
        case 3:
            result = A.multiply(B);
            cout << "Result of multiplication:\n";
            result.display();
            break;
        default:
            cerr << "Invalid choice\n";
            break;
    }

    return 0;
}