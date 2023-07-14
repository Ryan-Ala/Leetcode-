#include<iostream>
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int** ret = (int**)malloc((gridSize) * sizeof(int*));
    for (int i = 0; i < gridSize; i++)
        ret[i] = (int*)malloc((*gridColSize) * sizeof(int));
    ret[0][0] = grid[0][0];
    for (int i = 1; i < *gridColSize; i++)
        ret[0][i] = grid[0][i] + ret[0][i - 1];
    for (int i = 1; i < gridSize; i++)
        ret[i][0] = grid[i][0] + ret[i - 1][0];
    for (int i = 1; i < gridSize; i++)
        for (int j = 1; j < *gridColSize; j++)
            ret[i][j] = fmin(ret[i - 1][j], ret[i][j - 1]) + grid[i][j];
    int mins = ret[gridSize - 1][*gridColSize - 1];
    for (int i = 0; i < gridSize; i++)
        free(ret[i]);
    free(ret);
    return mins;
}