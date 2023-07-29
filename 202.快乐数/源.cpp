#include<iostream>
bool isHappy(int n) {
    int ret[10000] = { 0 };
    int num = 0;
    while (ret[num] != 2)
    {
        num = 0;
        while (n)
        {
            num += pow(n % 10, 2);
            n /= 10;
        }
        //printf("%d\n",num);
        if (num == 1)
            return 1;
        else if (num > 500)
            return 0;
        ret[num]++;
        n = num;
    }
    return 0;
}