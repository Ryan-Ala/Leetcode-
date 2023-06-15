#include<iostream>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int ret[201] = { 0 }, max = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ret[nums[i]]++;
        if (max < ret[nums[i]])
            max = ret[nums[i]];
    }
    int** res = (int**)malloc(sizeof(int*) * max);
    *returnColumnSizes = (int*)malloc(sizeof(int) * max);
    int k = 0, j = 0;
    while (numsSize)
    {
        j = 0;
        res[k] = (int*)malloc(201 * sizeof(int));
        for (int i = 1; i < 201; i++)
        {
            if (ret[i])
            {
                res[k][j++] = i;
                ret[i]--;
                numsSize--;
            }
        }
        (*returnColumnSizes)[k++] = j;
    }
    *returnSize = k;
    return res;
}