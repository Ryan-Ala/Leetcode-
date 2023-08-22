#include<iostream>
using namespace std;
int main()
{
	int a = 0, sum = 0, num = 0;
	cin >> a;
	for (int j = 0; j < 5; j++)
	{
	    sum =sum+ a;
	    a *= 10;
	    num += sum;
	}
	cout << num << endl;
}