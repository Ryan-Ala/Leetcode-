struct Hash
{
    int val;
    int count;
    UT_hash_handle hh;
};

int Hash_sort(struct Hash* a, struct Hash* b)
{
    return a->count < b->count;
}


int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    struct Hash* Hash = NULL, * temp = NULL, * p = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        HASH_FIND_INT(Hash, &nums[i], temp);
        if (!temp)
        {
            temp = (struct Hash*)malloc(sizeof(struct Hash));
            temp->val = nums[i];
            temp->count = 1;
            HASH_ADD_INT(Hash, val, temp);
        }
        else
            temp->count++;
    }
    temp = NULL;
    (*returnSize) = 0;
    int* ret = (int*)malloc(sizeof(int) * k);
    HASH_SORT(Hash, Hash_sort);
    HASH_ITER(hh, Hash, temp, p)
    {
        k--;
        ret[(*returnSize)++] = temp->val;
        if (k == 0)
        {
            HASH_ITER(hh, Hash, temp, p)
            {
                HASH_DEL(Hash, temp);
                free(temp);
            }
            return ret;
        }

    }