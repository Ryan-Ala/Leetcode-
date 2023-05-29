#include<iostream>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    for (int i = 0; i < pricesSize - 1; i++)
    {
        for (int j = i + 1; j < pricesSize; j++)
        {
            if (prices[i] >= prices[j])
            {
                prices[i] -= prices[j];
                break;
            }
        }
    }
    *returnSize = pricesSize;
    return prices;
}