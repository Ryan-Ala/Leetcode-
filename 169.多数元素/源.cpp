#include<stdlib.h>
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int majorityElement(int* nums, int numsSize) {
    int num = 0, count = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    num = nums[0];
    for (int i = 0; i < numsSize;)
    {
        if (nums[i] == num)
        {
            count++;
            i++;
        }
        else
        {
            num = nums[i];
            count = 0;
        }
        if (count > numsSize / 2)
            return num;
    }
    return 0;
}