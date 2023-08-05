#include<iostream>
int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize < 3)
    {
        if (matrixSize == 1)
            return matrix[0][0];
        if (matrixSize == 2)
        {
            int a = matrix[0][0] < matrix[0][1] ? matrix[0][0] : matrix[0][1];
            int b = matrix[1][0] < matrix[1][1] ? matrix[1][0] : matrix[1][1];
            return a + b;
        }

    }
    int** ret = (int**)malloc(sizeof(int*) * matrixSize);
    for (int i = 0; i < *matrixColSize; i++)
    {
        ret[i] = (int*)malloc(sizeof(int) * (*matrixColSize));
    }
    for (int i = 0; i < *matrixColSize; i++)
    {
        ret[0][i] = matrix[0][i];
    }
    int temp = 0;
    for (int i = 1; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            if (j == 0)
            {
                ret[i][0] = (ret[i - 1][0] < ret[i - 1][1] ? ret[i - 1][0] : ret[i - 1][1]) + matrix[i][0];
            }
            else if (j == (*matrixColSize - 1))
            {
                ret[i][*matrixColSize - 1] = (ret[i - 1][*matrixColSize - 2] < ret[i - 1][*matrixColSize - 1] ? ret[i - 1][*matrixColSize - 2] : ret[i - 1][*matrixColSize - 1]) + matrix[i][*matrixColSize - 1];
            }
            else
            {
                temp = (ret[i - 1][j - 1] < ret[i - 1][j] ? ret[i - 1][j - 1] : ret[i - 1][j]);
                ret[i][j] = (temp < ret[i - 1][j + 1] ? temp : ret[i - 1][j + 1]) + matrix[i][j];
            }
        }
    }
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    int min = ret[matrixSize - 1][0];
    for (int i = 0; i < matrixSize; i++)
    {
        if (min > ret[matrixSize - 1][i])
            min = ret[matrixSize - 1][i];
    }
    for (int i = 0; i < matrixSize; i++)
    {
        free(ret[i]);
    }
    free(ret);
    return min;
    return 0;
}