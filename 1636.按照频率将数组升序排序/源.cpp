#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b)
{
    return ((int*)a)[0] < ((int*)b)[0];
}
int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int ret[201][2] = { 0 };
    int* res = (int*)calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        ret[nums[i] + 100][0]++;
        ret[nums[i] + 100][1] = nums[i];
    }
    qsort(ret, 201, sizeof(ret[0]), cmp);
    int k = 0, i = 0;
    printf("%d", ret[0][0]);
    while (ret[i][0] != 0)
    {
        while (ret[i][0] != 0)
        {
            res[k++] = ret[i][1];
            ret[i][0]--;
        }
        i++;
    }
    int left = 0, right = numsSize - 1, temp;
    while (left < right)
    {
        temp = res[left];
        res[left] = res[right];
        res[right] = temp;
        left++;
        right--;
    }
    return res;
}