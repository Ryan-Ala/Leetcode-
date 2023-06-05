#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp1(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
int cmp2(const void* a, const void* b)
{
    return *(int*)a < *(int*)b;
}
int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 1 || numsSize == 2)
    {
        *returnSize = numsSize;
        return nums;
    }
    int a = numsSize / 2, b = (numsSize + 1) / 2;
    int arr1[a], arr2[b], k = 0, j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i % 2 == 0)
        {
            arr2[k++] = nums[i];
        }
        else
        {
            arr1[j++] = nums[i];
        }
    }
    *returnSize = numsSize;
    qsort(arr2, (numsSize + 1) / 2, sizeof(int), cmp1);
    qsort(arr1, numsSize / 2, sizeof(int), cmp2);
    k = 0;
    j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i % 2 == 1)
        {
            nums[i] = arr1[k++];
        }
        else
        {
            nums[i] = arr2[j++];
        }
    }
    return nums;
}