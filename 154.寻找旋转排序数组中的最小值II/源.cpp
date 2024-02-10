int findMin(int* nums, int numsSize) {
    int left = 0, mid;
    numsSize--;
    while (left < numsSize)
    {
        mid = left + (numsSize - left) / 2;
        if (nums[mid] < nums[numsSize])
            numsSize = mid;
        else if (nums[mid] > nums[numsSize])
            left = mid + 1;
        else
        {
            numsSize--;
            /*  while(numsSize>left&&nums[numsSize-1]==nums[numsSize])
             numsSize--;
             if(numsSize==0||nums[numsSize-1]>nums[numsSize]||numsSize==0)
             return nums[numsSize];
             numsSize--; */
        }
    }
    return nums[left];
}