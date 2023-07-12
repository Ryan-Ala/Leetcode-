#include<iostream>
// 滚动数组
int maxProfit(int* prices, int pricesSize) {
    int num0 = 0, num1 = -prices[0], a, b;
    for (int i = 1; i < pricesSize; i++)
    {                 //不持有
        a = fmax(num0, num1 + prices[i]);
        //持有     //本来不持有     
        b = fmax(num1, num0 - prices[i]);
        num0 = a;
        num1 = b;
    }
    return num0;
}
/*
int maxProfit(int* prices, int pricesSize){
    int** dp=(int**)malloc(sizeof(int*)*pricesSize);
    for(int i=0;i<pricesSize;i++)
    {
        dp[i]=(int*)malloc(sizeof(int)*2);
    }
    //int dp[pricesSize][2]={0};
    dp[0][0]=0;       //不持有股票
    dp[0][1]=-prices[0];  //持有股票
    for(int i=1;i<pricesSize;i++)
    {                 //不持有
        dp[i][0]=fmax(dp[i-1][0],dp[i-1][1]+prices[i]);
                     //持有     //本来不持有
        dp[i][1]=fmax(dp[i-1][1],dp[i-1][0]-prices[i]);
    }
    int max=dp[pricesSize-1][0];
    for(int i=0;i<pricesSize;i++)
    {
        free(dp[i]);
    }
    free(dp);
    return max;
}
    */