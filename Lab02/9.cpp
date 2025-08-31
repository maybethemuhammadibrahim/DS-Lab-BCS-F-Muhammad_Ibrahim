/*
Implement a program to represent a sparse matrix using a dynamic 2D array.
=> Input matrix elements.
=> Display the matrix in normal form.
=> Display the matrix in compressed form (row, column, value).
*/
#include <iostream>
using namespace std;

void allocateMatrix(int **&matrix, int rows, int cols)
{
    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
}

void freeMatrix(int **&matrix, int rows)
{
    if (matrix != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;
    }
}

void generateCompressedMatrix(int **&arr, int rows, int cols, int **&compMatrix, int &rowsOfCompMatrix, int &colsOfCompMatrix)
{
   int nonZeroCount = 0;
   for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(arr[i][j] != 0)
                nonZeroCount++;
        }
    }

    cout << "Non-zero Count is " << nonZeroCount << endl;

    compMatrix = new int*[nonZeroCount];
    for(int i = 0; i < nonZeroCount; i++) {
        compMatrix[i] = new int[3];
    }
    // cout << "Mem allocated" << endl;

    rowsOfCompMatrix = 0;
    colsOfCompMatrix = 3;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(arr[i][j] != 0) {
                // cout << "Non Zero term written" << endl;
                compMatrix[rowsOfCompMatrix][0] = i;
                compMatrix[rowsOfCompMatrix][1] = j;
                compMatrix[rowsOfCompMatrix][2] = arr[i][j];
                rowsOfCompMatrix++;
            }
        }
    }
}

void displayMatrix(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ,";
        }
        cout << endl;
    }
}

int main()
{
    int **matrix = nullptr;
    int rows = 3, cols = 3;

    //test values to debug
    allocateMatrix(matrix, rows, cols);
    matrix[0][0] = 0; 
    matrix[0][1] = 0; 
    matrix[0][2] = 3; 

    matrix[1][0] = 0; 
    matrix[1][1] = 0; // zero
    matrix[1][2] = 5; // non-zero

    matrix[2][0] = 7; // non-zero
    matrix[2][1] = 0; // zero
    matrix[2][2] = 0; // zero

    cout << "Normal matrix is:  " << endl;
    displayMatrix(matrix, rows, cols);

    int **compressedMatrix = nullptr;
    int rowsOfCompMatrix, colsOfCompMatrix;
    
    generateCompressedMatrix(matrix, rows, cols, compressedMatrix, rowsOfCompMatrix, colsOfCompMatrix);
    cout << "Compressed matrix is: " << endl;
    displayMatrix(compressedMatrix, rowsOfCompMatrix, colsOfCompMatrix);

    freeMatrix(matrix, rows);
    freeMatrix(compressedMatrix, rowsOfCompMatrix);

    return 0;
}
