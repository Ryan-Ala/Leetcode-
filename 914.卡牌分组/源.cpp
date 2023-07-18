#include<iostream>

bool hasGroupsSizeX(int* deck, int deckSize) {
    int ret[10000] = { 0 }, max = 0, k = 0;
    for (int i = 0; i < deckSize; i++)
    {
        ret[deck[i]]++;
        if (ret[deck[i]] > max)
            max = ret[deck[i]];
    }
    printf("%d", max);
    for (int x = 2; x <= max; x++)
    {
        k = 0;
        for (int i = 0; i < 10000; i++)
        {
            if (ret[i] != 0)
            {
                if (ret[i] % x != 0)
                {
                    k = 1;
                    break;
                }
            }
        }
        if (k == 0)
            return 1;
    }
    return 0;
}