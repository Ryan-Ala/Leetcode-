#include<iostream>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    if (r * c != (matSize * (*matColSize)))
    {
        *returnSize = matSize;
        (*returnColumnSizes) = (int*)malloc(sizeof(int) * matSize);
        for (int i = 0; i < matSize; i++)
            (*returnColumnSizes)[i] = *matColSize;
        return mat;
    }
    int* ret = (int*)malloc(sizeof(int) * matSize * (*matColSize)), k = 0;
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < *matColSize; j++)
        {
            ret[k++] = mat[i][j];
        }
    }
    int** res = (int**)malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i++)
    {
        res[i] = (int*)malloc(sizeof(int) * c);
    }

    k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            res[i][j] = ret[k++];
        }
    }
    free(ret);
    *returnSize = r;
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++)
    {
        (*returnColumnSizes)[i] = c;
    }
    return res;
}