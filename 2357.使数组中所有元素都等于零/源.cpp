#include<iostream>
int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
int minimumOperations(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int count = 0, max = nums[numsSize - 1], a = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
            continue;
        a = nums[i];
        max -= a;
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[j] != 0)
                nums[j] = nums[j] - a > 0 ? nums[j] - a : 0;
        }
        count++;
        if (max == 0)
            return count;
    }
    printf("%d", count);
    return 0;
}