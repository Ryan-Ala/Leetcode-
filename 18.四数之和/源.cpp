#include<iostream>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int size = 100;
    int** ret = (int**)malloc(sizeof(int*) * size);
    *returnColumnSizes = (int*)malloc(sizeof(int) * size);
    *returnSize = 0;
    int i, j, k;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int m = i + 1; m < numsSize; m++)
        {
            if (m > i + 1 && nums[m] == nums[m - 1])
                continue;
            j = m + 1;
            k = numsSize - 1;
            while (j < k)
            {
                if ((long)nums[i] + nums[j] + nums[k] + nums[m] < target)
                    j++;
                else if ((long)nums[i] + nums[j] + nums[k] + nums[m] > target)
                    k--;
                else
                {
                    ret[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    (*returnColumnSizes)[*returnSize] = 4;
                    ret[*returnSize][0] = nums[i];
                    ret[*returnSize][1] = nums[j];
                    ret[*returnSize][2] = nums[k];
                    ret[*returnSize][3] = nums[m];
                    (*returnSize)++;
                    if (*returnSize == size)
                    {
                        size *= 2;
                        ret = (int**)realloc(ret, sizeof(int*) * size);
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * size);
                    }
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    k--;
                }
            }
        }
    }
    return ret;
}

