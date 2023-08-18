#include<iostream>
/*int mem[38]={0};
int tribonacci(int n){
    if(mem[n])
    return mem[n];
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    if(n==2)
    return 1;
    mem[n]=tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
    return mem[n];
}*/
int tribonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    int num1 = 0, num2 = 0, num3 = 1, sum = 1;
    for (int i = 2; i < n; i++)
    {
        num1 = num2;
        num2 = num3;
        num3 = sum;
        sum = num1 + num2 + num3;
    }
    return sum;
}