#include<iostream>

int rob(int* nums, int numsSize) {
    if (numsSize < 3)
    {
        if (numsSize == 1)
            return nums[0];
        else
            return nums[0] > nums[1] ? nums[0] : nums[1];
    }
    int num1 = nums[0], sum = nums[0] > nums[1] ? nums[0] : nums[1], num2, max = 0;
    for (int i = 2; i < numsSize - 1; i++)
    {
        num2 = sum;
        sum = fmax(num2, num1 + nums[i]);
        num1 = num2;
    }
    max = sum;
    num1 = nums[1], sum = nums[1] > nums[2] ? nums[1] : nums[2], num2 = 0;
    for (int i = 3; i < numsSize; i++)
    {
        num2 = sum;
        sum = fmax(num2, num1 + nums[i]);
        num1 = num2;
    }
    printf("%d\n", sum);
    if (max < sum)
        return sum;
    return max;
}