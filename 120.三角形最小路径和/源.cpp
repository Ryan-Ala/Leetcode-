#include<iostream>
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int* ret = (int*)malloc(sizeof(int) * (triangleColSize[triangleSize - 1]));
    for (int i = 0; i < triangleColSize[triangleSize - 1]; i++)
    {
        ret[i] = triangle[triangleSize - 1][i];
    }
    for (int i = triangleSize - 2; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            ret[j] = fmin(ret[j], ret[j + 1]) + triangle[i][j];
        }
    }
    int min = ret[0];
    free(ret);
    return min;
}