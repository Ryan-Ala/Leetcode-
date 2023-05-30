/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<iostream>
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int ret = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }
    int size = 0;
    int max = (ret == INT_MIN ? ret : ret & (-ret));
    for (int i = 0; i < 32; i++)
    {
        if (((max >> i) & 1) == 1)
        {
            size = i;
            break;
        }
    }

    int* rets = (int*)calloc(2, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >> size & 1 == 1)
            rets[0] ^= nums[i];
        else
            rets[1] ^= nums[i];
    }
    *returnSize = 2;
    return rets;
}