#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int ret1[1001] = { 0 }, ret2[1001] = { 0 };
    for (int i = 0; i < nums1Size; i++)
    {
        ret1[nums1[i]]++;
    }
    for (int i = 0; i < nums2Size; i++)
    {
        ret2[nums2[i]]++;
    }
    int k = 0, * ret = (int*)malloc(sizeof(int) * 1001);
    *returnSize = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (ret1[i] != 0 && ret2[i] != 0)
        {
            k = ret1[i] < ret2[i] ? ret1[i] : ret2[i];
            while (k--)
            {
                ret[(*returnSize)++] = i;
            }
        }
    }
    return ret;
}