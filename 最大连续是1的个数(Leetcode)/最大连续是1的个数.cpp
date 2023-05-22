
int findMaxConsecutiveOnes(int* nums, int numsSize) {

    int count = 0, num = 0, a;
    for (int i = 0; i <= numsSize; i++)
    {
        if (i < numsSize && nums[i] == 1)
            count++;
        else
        {
            if (num < count)
            {
                num = count;
            }
            count = 0;
        }
    }
    return num;
}