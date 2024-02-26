int findMin(int* nums, int numsSize) {
    int left = 0, mid = numsSize-- / 2;
    while (left < numsSize)
    {
        mid = left + (numsSize - left) / 2;
        if (nums[mid] < nums[numsSize])
            numsSize = mid;
        else
            left = mid + 1;
    }
    return nums[left];
}