#include<iostream>
using namespace std;
int climbStairs(int n);
int main()
{
    int a;
    cin >> a;
    cout << climbStairs(a) << endl;
}
int climbStairs(int n) 
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
    {
        int a = 1, b = 2, num = 0;
        for (int i = 3; i <= n; i++)
        {
            num = a;
            a = b;
            b = a + num;
        }
        return b;
    }
}
