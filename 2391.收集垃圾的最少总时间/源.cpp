#include<iostream>
int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
    int i = 0, m = 0, p = 0, g = 0, mk = 0, pk = 0, gk = 0;
    while (i < garbageSize)
    {
        for (int j = 0; j < strlen(garbage[i]); j++)
        {
            if (garbage[i][j] == 'M')
            {
                m++;
                while (mk < i)
                {
                    m += travel[mk];
                    mk++;
                }
                continue;
            }
            if (garbage[i][j] == 'P')
            {
                p++;
                while (pk < i)
                {
                    p += travel[pk];
                    pk++;
                }
                continue;
            }
            if (garbage[i][j] == 'G')
            {
                g++;
                while (gk < i)
                {
                    g += travel[gk];
                    gk++;
                }
                continue;
            }
        }
        i++;
    }
    return p + m + g;
}