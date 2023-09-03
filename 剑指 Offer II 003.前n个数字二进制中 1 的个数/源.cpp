#include<iostream>
int fun(int x)
{
    int count = 0;
    while (x != 0)
    {
        count++;
        x &= (x - 1);
    }
    return count;
}
int* countBits(int n, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * (n + 1));
    *returnSize = n + 1;
    for (int i = 0; i <= n; i++)
    {
        ret[i] = fun(i);
    }
    return ret;
}

/*
int fun(int x)
{
    int count=0;
   for(int i=0;x!=0&&i<32;i++)
    {
        if(x&1)
        count++;
        x>>=1;
    }
    return count;
}
int* countBits(int n, int* returnSize){
    int* ret=(int*)malloc(sizeof(int)*(n+1));
    *returnSize=n+1;
    for(int i=0;i<=n;i++)
    {
        ret[i]=fun(i);
    }
    return ret;
}
*/
