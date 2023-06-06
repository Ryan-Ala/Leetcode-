#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ret = (int*)malloc(nums1Size * sizeof(int));
    memset(ret, -1, sizeof(int) * nums1Size);
    *returnSize = nums1Size;
    //if(nums1Size=nums2Size)
    //ret[nums1Size-1]=-1;
    for (int i = 0; i < nums1Size; i++)
    {
        int j;
        for (j = 0; j < nums2Size; j++)
        {
            if (nums2[j] == nums1[i])
            {
                break;
            }
        }
        for (j++; j < nums2Size; j++)
        {
            if (nums2[j] > nums1[i])
            {
                ret[i] = nums2[j];
                break;
            }
        }
    }
    return ret;
}