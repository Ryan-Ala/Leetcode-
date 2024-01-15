void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void AdjustDown(int* ret, int parent, int numsize)
{
    int child = parent * 2 + 1;
    while (child < numsize)
    {
        if (child + 1 < numsize && ret[child + 1] < ret[child])
        {
            child++;
        }
        if (child<numsize && ret[parent]>ret[child])
        {
            Swap(&ret[child], &ret[parent]);
            parent = child;
            child = child * 2 + 1;
        }
        else
            break;
    }
}
int buyChoco(int* prices, int pricesSize, int money) {
    for (int i = (pricesSize - 2) / 2; i >= 0; i--)
    {
        AdjustDown(prices, i, pricesSize);
    }
    int size = pricesSize;
    for (int i = 0; i < 2; i++)
    {
        Swap(&prices[0], &prices[--size]);
        AdjustDown(prices, 0, size);
    }
    if (prices[pricesSize - 1] + prices[pricesSize - 2] > money)
        return money;
    return money - (prices[pricesSize - 1] + prices[pricesSize - 2]);
}