int minMaxGame(int* nums, int numsSize) {
    if (numsSize == 1)
        return nums[0];
    int k = 0;
    while (numsSize)
    {
        k = 0;
        for (int j = 0; j < numsSize; j += 2)
        {
            if (k % 2 == 0)
            {
                nums[k++] = nums[j] > nums[j + 1] ? nums[j + 1] : nums[j];
            }
            else if (k % 2 == 1)
            {
                nums[k++] = nums[j] < nums[j + 1] ? nums[j + 1] : nums[j];
            }
        }
        numsSize /= 2;
    }
    return nums[0];
    return 0;
}