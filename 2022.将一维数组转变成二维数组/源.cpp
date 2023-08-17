#include<iostream>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    if (m * n != originalSize)
    {
        *returnSize = 0;
        return NULL;
    }
    int** ret = (int**)malloc(sizeof(int*) * m);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * m);
    *returnSize = m;
    for (int i = 0; i < m; i++)
    {
        (*returnColumnSizes)[i] = n;
        ret[i] = (int*)malloc(sizeof(int) * n);
    }

    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ret[i][j] = original[k++];
        }
    }

    return ret;
}