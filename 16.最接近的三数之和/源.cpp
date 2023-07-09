#include<iostream>
int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int count = 0, j = 0, k = 0, sum = 0, num = 0, minsum = 0, max = 100000;
    for (int i = 0; i < numsSize - 2; i++)
    {
        j = i + 1;
        k = numsSize - 1;
        while (j < k)
        {
            sum = nums[i] + nums[j] + nums[k];
            num = abs(sum - target);
            if (sum == target)
                return target;
            else if (sum > target && j < k)
                k--;
            else if (sum < target && j < k)
                j++;
            if (abs(max) >= num)
            {
                max = num;
                minsum = sum;
            }

        }
    }
    return minsum;
}