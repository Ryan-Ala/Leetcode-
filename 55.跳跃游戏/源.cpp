static int max(int a, int b)
{
    return a > b ? a : b;
}
bool canJump(int* nums, int numsSize) {
    int maxdis = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (i <= maxdis)
        {
            maxdis = max(maxdis, i + nums[i]);
            if (maxdis >= numsSize - 1)
                return 1;
        }
    }
    return 0;
}