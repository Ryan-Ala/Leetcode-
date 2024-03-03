double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size1 = 0, size2 = 0;
    int* ret = (int*)malloc(sizeof(int) * (nums1Size + nums2Size)), k = 0;
    while (size1 < nums1Size && size2 < nums2Size)
    {
        if (nums1[size1] < nums2[size2])
            ret[k++] = nums1[size1++];
        else
            ret[k++] = nums2[size2++];
    }
    while (size1 < nums1Size)
    {
        ret[k++] = nums1[size1++];
    }
    while (size2 < nums2Size)
    {
        ret[k++] = nums2[size2++];
    }
    double a;
    if (k % 2)
    {
        a = ret[k / 2];
    }
    else {
        a = (ret[k / 2] + ret[k / 2 - 1]) / (double)2;
    }
    free(ret);
    return a;
}