#include<iostream>
#include<uthash.h>
struct Hash
{
    int val;
    int first;
    int last;
    int count;
    UT_hash_handle hh;
};
int cmp(struct Hash* a, struct Hash* b)
{
    return a->count < b->count;
}
int findShortestSubArray(int* nums, int numsSize) {
    struct Hash* Hash = NULL, * tmp = NULL, * p = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        HASH_FIND_INT(Hash, &nums[i], tmp);
        if (!tmp)
        {
            tmp = (struct Hash*)malloc(sizeof(struct Hash));
            tmp->val = nums[i];
            tmp->first = i;
            tmp->last = i;
            tmp->count = 1;
            HASH_ADD_INT(Hash, val, tmp);
        }
        else
        {
            tmp->count++;
            tmp->last = i;
        }
    }
    HASH_SORT(Hash, cmp);
    tmp = NULL;
    int minsize = numsSize, size = Hash->count;
    HASH_ITER(hh, Hash, tmp, p)
    {
        if (tmp->count != size)
            break;
        if (tmp->last - tmp->first < minsize)
            minsize = tmp->last - tmp->first;
    }
    return minsize + 1;
}