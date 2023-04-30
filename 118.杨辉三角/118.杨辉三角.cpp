#include<iostream>

bool isHappy(int n) {
    long long num = 0;
    while (1)
    {
        while (n)
        {
            num += (n % 10) * (n % 10);
            n /= 10;
        }
        n = num;
        if (num == 1)
        {
            return 1;
        }
        num = 0;
    }
}
int main()
{
    isHappy(19);
}