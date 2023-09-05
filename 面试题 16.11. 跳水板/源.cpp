#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* divingBoard(int shorter, int longer, int k, int* returnSize) {
    if (k == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    else if (shorter == longer)
    {
        int* ret = (int*)malloc(sizeof(int));
        ret[0] = shorter * k;
        *returnSize = 1;
        return ret;
    }
    else
    {
        int* ret = (int*)malloc(sizeof(int) * (k + 1));
        for (int i = 0; i <= k; i++)
        {
            ret[i] = shorter * (k - i) + longer * i;
        }
        *returnSize = k + 1;
        return ret;
    }
    return NULL;
}