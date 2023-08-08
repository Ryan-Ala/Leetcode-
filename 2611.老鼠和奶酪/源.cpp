#include<iostream>
static int cmp(const void* a, const void* b) {
    return *(int*)a < *(int*)b;
}

int miceAndCheese(int* reward1, int reward1Size, int* reward2, int reward2Size, int k) {
    int sum = 0, * ret = (int*)malloc(sizeof(int) * reward2Size);
    for (int i = 0; i < reward2Size; i++)
    {
        sum += reward2[i];
        ret[i] = reward1[i] - reward2[i];
    }
    qsort(ret, reward2Size, sizeof(int), cmp);
    for (int i = 0; i < k; i++)
        sum += ret[i];
    free(ret);
    return sum;
}