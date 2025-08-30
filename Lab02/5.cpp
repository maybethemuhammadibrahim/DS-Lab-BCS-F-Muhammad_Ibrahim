/*Write a C++ program that dynamically creates a 2D matrix and provides:
=> Addition of two matrices.
=> Subtraction of two matrices.
=> Ensure safe memory handling with proper allocation/deallocation.*/
#include <iostream>
using namespace std;

void allocate(int **&matrix, int &r, int &c)
{
    matrix = new int *[r];
    for (int i = 0; i < r; i++)
    {
        matrix[i] = new int[c];
    }
}

void arithmetic(int **&resultant, int **&matrix1, int **&matrix2, int r1, int c1, int r2, int c2, bool isAdd)
{
    if (r1 != r2 || c1 != c2) {
        return ;
    }
        

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            if (isAdd)
                resultant[i][j] = matrix1[i][j] + matrix2[i][j];
            else
                resultant[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

}

void display(int **&arr, int r, int c)
{
    // cout << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << ",";
        }
        cout << endl;
    }
}

void enterData(int **&matrix, int r, int c) {
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter element at (" << i+1 << "," << j+1 << "): ";
            cin >> matrix[i][j];
        }
        
    }
} 

void free(int **&matrix, int r) {
    for(int i = 0; i < r; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    int **matrix1, **matrix2, **resultant;
    int row1, col1, row2, col2;

    cout << "Enter number of rows of first matrix: ";
    cin >> row1;
    cout << "Enter number of columns of first matrix: ";
    cin >> col1;
    cout << "Enter number of rows of second matrix: ";
    cin >> row2;
    cout << "Enter number of columns of second matrix: ";
    cin >> col2;
    

    allocate(matrix1, row1, col1);
    allocate(matrix2, row2, col2);

    allocate(resultant, row1, col1); // assuming row1 == row2 and col1 == col2

    cout << "Enter Data for matrix 1" << endl;
    enterData(matrix1, row1, col1);
    cout << "\nEnter Data for matrix 2" << endl;
    enterData(matrix2, row2, col2);


    arithmetic(resultant, matrix1, matrix2, row1, col1, row2, col2, true);
    cout << "\nResult of Addition" << endl;
    display(resultant, row1, col1);
    arithmetic(resultant, matrix1, matrix2, row1, col1, row2, col2, false);
    cout << "\nResult of Subtraction" << endl;
    display(resultant, row1, col1);

    free(matrix1, row1);
    free(matrix2, row2);
    free(resultant, row1);
}
