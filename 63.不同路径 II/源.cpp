#include<iostream>
//二维数组
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    if (obstacleGridSize == 1 && *obstacleGridColSize == 1)
    {
        if (obstacleGrid[0][0] == 1)
            return 0;
        else
            return 1;

    }
    int** ret = (int**)malloc(sizeof(int*) * obstacleGridSize);
    for (int i = 0; i < obstacleGridSize; i++)
    {
        ret[i] = (int*)calloc(*obstacleGridColSize, sizeof(int));
    }
    ret[0][0] = 1;
    for (int i = 0; i < *obstacleGridColSize; i++)
    {
        if (obstacleGrid[0][i] == 1 || (i > 0 && ret[0][i - 1] == 0))
            ret[0][i] = 0;
        else
            ret[0][i] = 1;
    }
    for (int i = 0; i < obstacleGridSize; i++)
    {
        if (obstacleGrid[i][0] == 1 || (i > 0 && ret[i - 1][0] == 0))
            ret[i][0] = 0;
        else
            ret[i][0] = 1;
    }

    for (int i = 1; i < obstacleGridSize; i++)
    {
        for (int j = 1; j < *obstacleGridColSize; j++)
        {
            if (obstacleGrid[i][j] == 1)
                ret[i][j] == 0;
            else
                ret[i][j] = ret[i - 1][j] + ret[i][j - 1];

        }
    }

    int max = ret[obstacleGridSize - 1][*obstacleGridColSize - 1];
    for (int i = 0; i < obstacleGridSize; i++)
    {
        free(ret[i]);
    }
    free(ret);
    return max;

    return 0;
}


//优化后一维数组
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int* ret = (int*)calloc(*obstacleGridColSize, sizeof(int));
    if (obstacleGrid[0][0] == 1)
        ret[0] = 0;
    else
        ret[0] = 1;
    for (int i = 0; i < obstacleGridSize; i++)
    {
        for (int j = 0; j < *obstacleGridColSize; j++)
        {
            if (obstacleGrid[i][j] == 1)
                ret[j] = 0;
            else
            {
                if (j > 0)
                    ret[j] += ret[j - 1];
                else
                    continue;
            }
        }
        for (int i = 0; i < *obstacleGridColSize; i++)
            printf("%d  ", ret[i]);
        printf("\n");
    }
    int max = ret[*obstacleGridColSize - 1];
    free(ret);
    return max;
}