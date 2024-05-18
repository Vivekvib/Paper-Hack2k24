#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Matrix {
    public:
    int **arr;
    int rows, cols;

    public:
        Matrix(int, int);
        Matrix sum(Matrix);
        Matrix transpose();
        Matrix product(Matrix);
        void setElement(int i, int j, int value) {
            arr[i][j] = value;
        }
        void display();
       

};

Matrix :: Matrix(int row, int col) {
    rows = row;
    cols = col;
    arr = new int *[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int [cols];
    } 
}

void Matrix::display() {
    for (int i = 0; i < rows; i++) {
        cout << "[ ";
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "]";
        cout << endl;  
    }
}

Matrix Matrix :: sum(Matrix B) {
    Matrix temp(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp.arr[i][j] = arr[i][j] + B.arr[i][j];
        }
    }
    return temp;
}

Matrix Matrix :: transpose() {
    Matrix temp(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp.arr[i][j] = arr[j][i];
        } 
    }
    return temp;
}

Matrix Matrix :: product(Matrix B) {
    Matrix temp(rows, B.cols);
    try {
        if(cols != B.rows) {
            throw invalid_argument("The column of matrix A is not equals to the rows of the Matrix B!!");
        }
        else {
            for (int i = 0; i < rows; i++){
                for (int j = 0; j < B.cols; j++){
                    int sum = 0;
                    for (int k = 0; k < cols; k++)
                    {
                        sum = sum + (arr[i][k] * B.arr[k][j]);
                    }  
                    temp.arr[i][j] = sum; 
                }
            }
            return temp;
        }
    }
    catch (const exception& e) {
        cout << "Exception_error: " << e.what() << endl;
        exit(0);
    }
}

int main()
{
    string choice;
    while(true) {
        cout << "\n#---------------MENU---------------#\n";
        cout << "-------*---------*---------*-------\n";
        cout << " 1. SUM of a matrix.......\n";
        cout << " 2. TRANSPOSE of a matrix......\n";
        cout << " 3. PRODUCT of a matrix.......\n";
        cout << "-------*---------*---------*-------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        int m, n;
        cout << " Enter the row of the matrix: ";
        cin >> m;
        cout << " Enter the col of the matrix: ";
        cin >> n;

        Matrix A(m,n);
        Matrix B(m, n);
        cout << "Enter element of matrix A row by row: \n";

        int i, j, val;
        for ( i = 0; i < m; i++)
        {
            for ( j = 0; j < n; j++)
            {
                cin >> val;
                A.setElement(i, j, val);
            }
        }

        cout << " Entered matrix A: \n";
        A.display();
        cout << endl;

        if(choice == "1" || choice == "3"){
            cout << "Enter element of matrix B row by row: \n";
            for ( i = 0; i < m; i++){
                for ( j = 0; j < n; j++){
                    cin >> val;
                    B.setElement(i, j, val);
                }
            }
            cout << " Entered matrix B: \n";
            B.display();
            cout << endl;
        }
       

        if(choice == "1") {
            Matrix res = A.sum(B);
            cout << " Sum of the matrix A and B: \n";
            res.display();
        }
        else if(choice == "2") {
            Matrix tran = A.transpose();
            cout << " Transpose of the matrix: \n";
            tran.display();
        }
        else if(choice == "3") {
            Matrix prod = A.product(B);
            cout << " Product of the matrix A and B: \n";
            prod.display();
        }
        
        string yesOrNo;
        cout << " Do you want to continue..? (Y/N): ";
        cin >> yesOrNo;
        cout << endl;
        if(yesOrNo != "y" && yesOrNo != "Y") break;
       
    }    
    
    return 0;
}
