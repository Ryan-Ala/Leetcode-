#include<iostream>
    void moveZeroes(int* nums, int numsSize) {
        int k = 0;
        for (int i = 0; i < numsSize - k;)
        {
            if (nums[i] == 0)
            {
                k++;
                for (int j = i; j < numsSize - 1; j++)
                {
                    nums[j] = nums[j + 1];
                }
                nums[numsSize - 1] = 0;
            }
            else
            {
                i++;
            }
        }
        return 0;
    }