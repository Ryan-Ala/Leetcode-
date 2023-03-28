#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRigthDifference(int* nums, int numsSize, int* returnSize) {
    int* left = (int*)malloc(sizeof(int) * numsSize);
    int* right = (int*)malloc(sizeof(int) * numsSize);
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    left[0] = 0;
    right[numsSize - 1] = 0;
    int lef = 0, righ = 0;
    for (int i = 1; i < numsSize; i++)
    {
        lef += nums[i - 1];
        righ += nums[numsSize - i];
        left[i] = lef;
        right[numsSize - 1 - i] = righ;
    }
    for (int i = 0; i < numsSize; i++)
    {
        int an = left[i] - right[i];
        ans[i] = an >= 0 ? an : -an;
    }
    *returnSize = numsSize;
    return ans;
}