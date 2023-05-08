#include <iostream>
using namespace std;
void function(double p, double a, int n)
{
    p *= a;
    if (n == 1)
        p -= 50;
    if (p >= 0)
        printf("%.2f", p);
    else
        printf("%.2f", 0.00);
}
int main() {
    double price;
    int month, day, n;
    cin >> price >> month >> day >> n;
    if (month == 12 && day == 12)
    {
        function(price, 0.8, n);
    }
    else if (month == 11 && day == 11)
    {
        function(price, 0.7, n);
    }
    else
    {
        function(price, 1, n);
    }
}