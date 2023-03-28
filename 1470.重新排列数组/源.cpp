#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    int k = 0, sz = numsSize / 2;
    for (int i = 0; i < sz; i++)
    {
        ret[k++] = nums[i];
        ret[k++] = nums[sz + i];
    }
    *returnSize = numsSize;
    return ret;
}