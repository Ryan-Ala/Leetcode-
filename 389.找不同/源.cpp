#include<iostream>
char findTheDifference(char* s, char* t) {
    int num[26], count = 0;
    int ss = strlen(s), tt = strlen(t);
    memset(num, 0, sizeof(num));
    for (int i = 0; i < ss; i++)
    {
        count = s[i] - 'a';
        num[count]++;
        count = t[i] - 'a';
        num[count]--;
    }
    num[t[ss] - 'a']--;
    for (int i = 0; i < 26; i++)
    {
        if (num[i] < 0)
            return 'a' + i;
    }
    return ' ';
}