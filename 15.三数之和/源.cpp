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
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int size = 100;
    int** ret = (int**)malloc(sizeof(int*) * size);
    *returnColumnSizes = (int*)malloc(sizeof(int) * size);
    *returnSize = 0;
    int i, j, k;
    //排序
    qsort(nums, numsSize, sizeof(int), cmp);
    for (i = 0; i < numsSize; i++) {
        //先确定第三个数的值，再对剩下的两个数进行两数之和的操作
        //若本次的第三个数与上一次的情况相同，则跳过这个数
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        //给定nums[i]，以j，k作为双指针进行两数之和操作
        j = i + 1;
        k = numsSize - 1;
        while (j < k)
        {
            if (nums[i] + nums[j] + nums[k] < 0)
                j++;
            else if (nums[i] + nums[j] + nums[k] > 0)
                k--;
            else
            {
                ret[*returnSize] = (int*)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[j];
                ret[*returnSize][2] = nums[k];
                (*returnSize)++;
                if (*returnSize == size)
                {
                    size *= 2;
                    ret = (int**)realloc(ret, sizeof(int*) * size);
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * size);
                }
                int num1 = nums[j], num2 = nums[k];
                while (nums[j] == num1 && j < k)
                    j++;
                while (nums[k] == num2 && j < k)
                    k--;
            }
        }
    }
    return ret;
}
