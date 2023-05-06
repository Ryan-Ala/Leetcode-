#include<iostream>


int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int cmp(int* a, int* b)
    {
        return *a - *b;
    }
    qsort(g, gSize, sizeof(int), &cmp);
    qsort(s, sSize, sizeof(int), &cmp);
    int count = 0;
    for (int i = 0, j = 0; j < sSize && i < gSize;)
    {
        if (s[j] >= g[i])
        {
            count++;
            j++;
            i++;
        }
        else
        {
            j++;
        }
    }
    return count;
}
