#include<iostream>
int maxProfit(int* prices, int pricesSize) {
    int maxProfit = 0;
    int minPrice = prices[0];
    int i;
    for (i = 0; i < pricesSize; i++) {
        if (minPrice > prices[i])
            minPrice = prices[i];

        if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;
    }
    return maxProfit;

}