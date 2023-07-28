#include<iostream>
int min(int a, int b)
{
    return a > b ? b : a;
}
int minCostClimbingStairs(int* cost, int costSize) {
    int* ret = (int*)malloc(sizeof(int) * (1 + costSize));
    ret[0] = 0;
    ret[1] = 0;
    for (int i = 2; i <= costSize; i++)
    {
        ret[i] = min(ret[i - 1] + cost[i - 1], ret[i - 2] + cost[i - 2]);
    }
    int res = ret[costSize];
    free(ret);
    return res;
}