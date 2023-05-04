int maximumProduct(int* nums, int numsSize) {
    if (numsSize == 3)
        return nums[0] * nums[1] * nums[2];
    int cmp(const void* a, const void* b)
    {
        return *(int*)a - *(int*)b;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int a = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3], b = nums[0] * nums[1] * nums[numsSize - 1];
    return a > b ? a : b;
    return 0;
}
·µ