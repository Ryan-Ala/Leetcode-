#include<iostream>
int maxAscendingSum(int* nums, int numsSize) {
    int count = nums[0], maxcount = count;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            count += nums[i + 1];
            if (maxcount < count)
                maxcount = count;
        }
        else
            count = nums[i + 1];
    }
    return maxcount;
}