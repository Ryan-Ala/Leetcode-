#include<iostream>
int lengthOfLongestSubstring(char* s) {
    if (!*s) { return 0; }
    int ret[127][2] = { 0 }, count = 0, maxcount = 0;
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        j = s[i];
        if (ret[j][0] == 0)
        {
            ret[j][0]++;
            ret[j][1] = i;
            count++;
        }
        else
        {
            count = 0;
            i = ret[j][1];
            for (int k = 0; k < 2; k++)
                for (int h = 0; h < 127; h++)
                {
                    ret[h][k] = 0;
                }
        }
        if (maxcount < count)
            maxcount = count;
    }
    return maxcount;
}