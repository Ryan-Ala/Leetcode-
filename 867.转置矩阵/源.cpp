#include<iostream>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int** ret = (int**)malloc(sizeof(int*) * (*matrixColSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*matrixColSize));
    for (int i = 0; i < *matrixColSize; i++)
    {
        ret[i] = (int*)malloc(sizeof(int) * matrixSize);
        for (int j = 0; j < matrixSize; j++)
        {
            ret[i][j] = matrix[j][i];
        }
        (*returnColumnSizes)[i] = matrixSize;
    }
    *returnSize = *matrixColSize;
    return ret;
}