#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    if (numsSize < 2)
    {
        if (numsSize == 0)
        {
            ret[0] = -1;
            ret[1] = -1;
            return ret;
        }
        if (numsSize == 1)
        {
            if (nums[0] == target)
            {
                ret[0] = 0;
                ret[1] = 0;
                return ret;
            }
            else
            {
                ret[0] = -1;
                ret[1] = -1;
                return ret;
            }

        }
    }
    printf("aa");
    int left = 0, right = numsSize - 1, mid = 0, k = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
        {
            printf("aa");
            k = 0;
            break;
        }
    }
    if (k == -1)
    {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    for (int i = mid; i < numsSize; i++)
    {
        if (nums[mid] != nums[i])
        {
            ret[1] = i - 1;
            break;
        }
        if (i + 1 == numsSize)
        {
            ret[1] = i;
            break;
        }
    }
    for (int i = mid; i >= 0; i--)
    {
        if (nums[mid] != nums[i])
        {
            ret[0] = i + 1;
            break;
        }
        if (i - 1 < 0)
        {
            ret[0] = i;
            break;
        }
    }
    return ret;
}