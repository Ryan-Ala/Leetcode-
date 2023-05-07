#include<iostream>
int lengthOfLastWord(char* s) {
    int count = 0, num = 0, sz = strlen(s);
    for (int i = sz - 1; i >= 0; i--)
    {
        if ((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A')) //判断是不是字母，是则count+1
            count++;
        else
        {
            if (count > 0 && s[i] == ' ')
                break;
        }
    }
    return count;
}
