#include<iostream>
int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
int singleNumber(int* nums, int numsSize) {
    if (numsSize < 4)
    {
        if (numsSize == 1)
            return nums[0];
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[numsSize - 1] != nums[numsSize - 2])
        return nums[numsSize - 1];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            return nums[i];
    }
    return 0;
}