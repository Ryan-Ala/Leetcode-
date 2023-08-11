#include<iostream>
int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int* in = (int*)calloc(n + 1, sizeof(int));
    int* out = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i < trustSize; i++)
    {
        in[trust[i][1]]++;
        out[trust[i][0]]++;
    }
    for (int i = 1; i < n + 1; i++)
    {
        if (in[i] == n - 1 && out[i] == 0)
            return i;
    }
    return -1;
}