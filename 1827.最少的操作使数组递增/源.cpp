int minOperations(int* nums, int numsSize) {
    if (numsSize == 1)
        return 0;
    int count = 0, size = 0;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] >= nums[i + 1])
        {
            size = nums[i + 1];
            nums[i + 1] = nums[i] + 1;
            count += nums[i + 1] - size;
        }
    }
    return count;
}