#include<iostream>
int missingNumber(int* nums, int numsSize) {
    for (int i = 0; i <= numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (i == nums[j])
                break;
            if (j == numsSize - 1)
                return i;
        }
    }
    return 0;
}