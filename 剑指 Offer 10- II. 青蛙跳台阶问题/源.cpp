/*int mem[101]={0};
int numWays(int n){
    if(mem[n])
    return mem[n];
    if(n==1||n==0)
    return 1;
    if(n==2)
    return 2;
    mem[n]=(numWays(n-1)+numWays(n-2))%(1000000007);
    return mem[n];
}*/

int numWays(int n) {
    if (n == 0 || n == 1)
        return 1;
    if (n == 2)
        return 2;
    int sum = 2, num1 = 1, num2 = 1;
    for (int i = 2; i < n; i++)
    {
        num1 = num2;
        num2 = sum;
        sum = (num1 + num2) % 1000000007;
    }
    return sum;
}