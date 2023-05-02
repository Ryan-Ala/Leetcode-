#include<stdlib.h>
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 1)
        return 0;
    int** ret = (int**)malloc(sizeof(int*) * (pricesSize - 1));
    for (int i = pricesSize - 1; i > 0; i--)
        ret[pricesSize - i - 1] =(int*) malloc(sizeof(int) * i);
    for (int i = 0; i < pricesSize - 1; i++)
        for (int j = 0; j < pricesSize - 1 - i; j++)
        {
            ret[i][j] = prices[i + j + 1] - prices[i];
        }
    int max = ret[0][0];
    for (int i = 0; i < pricesSize - 1; i++)
        for (int j = 0; j < pricesSize - 1 - i; j++)
        {
            if (max < ret[i][j])
                max = ret[i][j];
        }
    if (max > 0)
        return max;
    else
        return 0;
}
