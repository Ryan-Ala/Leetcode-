#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0, j = numsSize - 1;
    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    while (j >= 0 && nums[j] > target)
        j--;
    while (i < j)
    {
        if (nums[i] + nums[j] == target)
        {
            ret[0] = nums[i];
            ret[1] = nums[j];
            break;
        }
        while (j >= 0 && nums[i] + nums[j] > target)
            j--;
        while (i < numsSize && nums[i] + nums[j] < target)
            i++;
    }
    return ret;
}