#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)   //rowIndex 是杨辉三角的行  *returnSize是杨辉三角每列的元素个数
{

    int** ret = (int**)malloc(sizeof(int*) * (rowIndex + 1));   //动态分配一个二维数组，这里先分配了行
    for (int i = 0; i <= rowIndex; i++)
    {
        ret[i] = (int*)malloc(sizeof(int) * (i + 1));          //动态分配了二维数组每行中的元素
        ret[i][i] = ret[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
    }
    *returnSize = rowIndex + 1; 
    return ret[rowIndex];   //返回动态数组的行坐标
}