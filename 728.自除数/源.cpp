#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize)
{
    int k = 0, num;
    int* ret = (int*)malloc(0);
    for (int i = left; i <= right; i++)
    {
        num = i;
        while (num)
        {
            if ((num % 10) == 0 || i % (num % 10) != 0)
                break;
            num /= 10;
        }
        if (num == 0)
        {
            ret = (int*)realloc(ret, sizeof(int) * (++k));
            ret[k - 1] = i;
        }
    }
    *returnSize = k;
    return ret;
}