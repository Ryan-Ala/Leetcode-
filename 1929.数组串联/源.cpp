#include<stdlib.h>
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 2 * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        ret[i + numsSize] = nums[i];
        ret[i] = ret[i + numsSize];
    }
    *returnSize = 2 * numsSize;
    return ret;
}