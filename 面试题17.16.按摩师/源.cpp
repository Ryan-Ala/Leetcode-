#include<iostream>
int fvmax(int a, int b)
{
    return a > b ? a : b;
}
int massage(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2)
        return nums[1] > nums[0] ? nums[1] : nums[0];
    int* ret = (int*)malloc(sizeof(int) * numsSize), max = 0;
    ret[0] = nums[0];
    ret[1] = nums[1] > nums[0] ? nums[1] : nums[0];
    for (int i = 2; i < numsSize; i++)
    {
        ret[i] = fvmax(ret[i - 1], ret[i - 2] + nums[i]);
    }
    int maxs = ret[numsSize - 1];
    return maxs;
}