#include<iostream>
int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {
    int** ret = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++)
    {
        ret[i] = (int*)calloc(n, sizeof(int));
    }
    for (int i = 0; i < indicesSize; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ret[indices[i][0]][j]++;
        }
    }
    for (int i = 0; i < indicesSize; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ret[j][indices[i][1]]++;
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ret[i][j] % 2 == 1)
                count++;
        }
    }
    for (int i = 0; i < m; i++)
        free(ret[i]);
    free(ret);
    return count;

}