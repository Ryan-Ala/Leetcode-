int cmp(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}
int* subSort(int* array, int arraySize, int* returnSize) {
    if (arraySize == 0 || arraySize == 1)
    {
        *returnSize = 2;
        int* res = (int*)malloc(sizeof(int) * 2);
        res[0] = -1;
        res[1] = -1;
        return res;
    }
    int* ret = (int*)malloc(sizeof(int) * arraySize);
    memmove(ret, array, sizeof(int) * arraySize);
    qsort(array, arraySize, sizeof(int), cmp);
    int* res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int left = 0, right = arraySize - 1;
    while (left < arraySize && array[left] == ret[left])
    {
        left++;
    }
    while (right >= 0 && array[right] == ret[right])
    {
        right--;
    }
    if (left >= right)
    {
        res[0] = -1;
        res[1] = -1;
        return res;
    }
    res[0] = left;
    res[1] = right;
    free(ret);
    return res;
}