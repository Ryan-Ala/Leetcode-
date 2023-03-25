#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int max = 0;
    for (int i = 0; i < candiesSize; i++)
    {
        if (candies[i] > max)
            max = candies[i];
    }
    bool* ret = (bool*)malloc(sizeof(bool) * candiesSize);
    *returnSize = candiesSize;
    for (int i = 0; i < candiesSize; i++)
    {
        if (candies[i] + extraCandies >= max)
            ret[i] = 1;
        else
            ret[i] = 0;
    }
    return ret;
}