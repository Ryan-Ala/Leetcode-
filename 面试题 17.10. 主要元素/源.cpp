#include<iostream>
int majorityElement(int* nums, int numsSize) {
    int count = 0, num = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == num)
            count++;
        else
        {
            count--;
            if (!count && i < numsSize - 1)
            {
                num = nums[i + 1];
            }
        }
    }
    int i = 0;
    for (int j = 0; j < numsSize; j++)
    {
        if (num == nums[j])
            i++;
    }
    return i * 2 > numsSize ? num : -1;
}