#include<iostream>
int pivotIndex(int* nums, int numsSize) {
    int sum = 0, leftsize = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (2 * leftsize == (sum - nums[i]))
            return i;
        leftsize += nums[i];
    }
    return -1;
}