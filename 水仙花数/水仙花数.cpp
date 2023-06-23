#include<iostream>
#include<math.h>
using namespace std;
inline int weishu(int j);
inline void shuixian(int i,int n);
int main()
{
	for (long long j = 1; j <= 100000; j++)
	{
		int n = weishu(j);
		 shuixian(j,n);
	}
}
void shuixian(int i,int n)
{
	long long sum = 0;
	for (long long j = i; j > 0; j /= 10)
	{
		sum += pow((j%10),n);
	}
	if (sum == i)
	{
		cout << i << endl;
	}
}
int weishu(int j)
{
	int i=0;
	while (j > 0)
	{
		j /= 10;
		i++;
	}
	return i;
}