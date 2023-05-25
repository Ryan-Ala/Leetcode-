#include<iostream>
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int temp = 0;
    for (int i = 0; i < matrixSize / 2; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - 1 - i][j];
            matrix[matrixSize - 1 - i][j] = temp;
        }
    }
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < i; j++)         //j要小与i，否则会失败
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}