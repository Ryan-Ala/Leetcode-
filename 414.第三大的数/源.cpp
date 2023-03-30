#include<iostream>
int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
int thirdMax(int* nums, int numsSize) {
    int thirdmax = 0;
    if (numsSize == 1)
        return nums[0];
    else if (numsSize == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];
    else
    {
        qsort(nums, numsSize, sizeof(int), cmp);
        thirdmax = nums[numsSize - 1];
        int k = 0;
        for (int i = numsSize - 2; i >= 0 && k != 2; i--)
        {
            if (thirdmax != nums[i])
            {
                thirdmax = nums[i];
                k++;
            }
        }
        if (k == 1)
        {
            return nums[numsSize - 1];
        }
    }
    return thirdmax;
}