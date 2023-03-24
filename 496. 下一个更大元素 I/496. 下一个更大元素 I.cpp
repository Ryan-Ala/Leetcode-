#include<iostream>
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* ret = (int*)malloc(sizeof(int) * nums1Size);
    if (nums1Size = nums2Size)
        ret[nums1Size - 1] = -1;
    for (int i = 0; i < nums1Size; i++)
    {
        int j = 0;
        for (j = i + 1; j < nums2Size; j++)
        {
            if (nums2[j] > nums1[i])
                ret[i] = nums2[j];
        }
        if (j == nums2Size)
            ret[i] = -1;
    }
    return ret;
}
int main()
{
    int nums1[] = { 4,1,2 }, nums2[] = { 1,3,4,2 }, nums1Size = 3, nums2Size = 4;
    nextGreaterElement(nums1,nums1Size,nums2,nums2Size);
}