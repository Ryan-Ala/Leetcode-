#include<iostream>
int maxs(int a, int b)
{
    return a > b ? a : b;
}
int maxSubArray(int* nums, int numsSize) {
    int max = 0, count = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        max = maxs(max + nums[i], nums[i]);
        if (max > count)
            count = max;
    }
    return count;
}