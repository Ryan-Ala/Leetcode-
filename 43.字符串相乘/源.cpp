#include<iostream>
char* multiply(char* num1, char* num2) {
    if (num1[0] == '0' || num2[0] == '0')
        return "0";
    int size1 = strlen(num1) - 1, size2 = strlen(num2) - 1;
    char* ret = (char*)malloc(size1 + size2 + 4);
    int numsize = size1 + size2 + 2, res = numsize, num = 0, size = 0;
    for (int i = numsize; i > -1; i--)
    {
        ret[i] = '0';
    }
    ret[numsize + 1] = '\0';
    for (int i = size1; i > -1; i--)
    {
        numsize = res;
        res--;
        size = num1[i] - '0';
        num = 0;
        for (int j = size2; j > -1; j--)
        {
            num += (num2[j] - '0') * size + ret[numsize] - '0';
            ret[numsize--] = num % 10 + '0';
            num /= 10;
        }
        while (num != 0)
        {
            ret[numsize--] = num % 10 + '0';
            num /= 10;
        }
    }
    while (num != 0)
    {
        ret[numsize--] = num % 10 + '0';
        num /= 10;
    }
    return ret + numsize + 1;
}