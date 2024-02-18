#include<iostream>
int* missingTwo(int* nums, int numsSize, int* returnSize) {
    int count = 0, size = 0;
    *returnSize = 2;
    int* ret = (int*)calloc(2, sizeof(int));
    for (int i = 1; i <= numsSize + 2; i++)
    {
        count ^= i;
    }
    for (int i = 0; i < numsSize; i++)
    {
        count ^= nums[i];
    }
    for (int i = 1; i <= 32; i++)
    {
        if (count & 1)
            break;
        size++;
        count >>= 1;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >> size & 1)
            ret[0] ^= nums[i];
        else
            ret[1] ^= nums[i];
    }
    for (int i = 1; i <= numsSize + 2; i++)
    {
        if (i >> size & 1)
            ret[0] ^= i;
        else
            ret[1] ^= i;
    }
    return ret;
}