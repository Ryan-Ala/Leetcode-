/*找出一个只出现过一次的数字的问题处理方法就是找一个数字把里面所有的数字都异或一遍，
利用异或两次等于没异或的特点来处理。那么如果有两个数字都只出现了一次，那么如此得到
的应该是两个数异或的结果。首先这个结果肯定不是0（要不然就全都配对了），所以里面一定
至少一位是一。找出值为1的一位，以这一位的值将结果分为两组。例如1 2 3 4 1 2，异或完的
结果应该是3 ^ 4得到的111，那么随便找一位就行了。例如找最低位，那么这一位是1的有1 3 1，
是0的有2 4 2，由于是利用异或结果为1的某一位分的组，所以两个待查询数字一定分别在两组中。
所以再找两个变量，分别异或两组数，即可找到这两个数。*/
#include<iostream>
using namespace std;
void fun(int* nums,int numsize,int *a,int* b)
{
	int ret = 0, pos = 0;
	for (int i = 0; i < numsize; i++)
	{
		ret ^= nums[i];
	}
	for (int i = 0; i < 32; i++)
	{
		if (((ret >> i) &1)== 1)
		{
			pos = i;
		}
	}
	for (int i = 0; i < numsize; i++)
	{
		if (((nums[i] >> pos) & 1) == 1)
			*a = nums[i];
		else
			*b = nums[i];
	}
}
int main()
{
	int a = 0, b = 0;
	int arr[] = { 1,1,2,2,3,3,5,5,8,3,3,9 };
	fun(arr, sizeof(arr) / sizeof(int), &a, &b);
	cout << a << "  " << b << endl;
}