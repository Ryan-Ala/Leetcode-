#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
    int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 1) { *returnSize = numsSize; return nums; }
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    int i = 0, j = numsSize - 1;
    *returnSize = numsSize;
    while (numsSize > 0)
    {
        if (nums[numsSize - 1] % 2 == 0)
        {
            ret[i++] = nums[numsSize - 1];
        }
        else
        {
            ret[j--] = nums[numsSize - 1];
        }
        numsSize--;
    }
    return ret;
}