#include<iostream>
using namespace std;
int add(int, int);
int sub(int, int);
int mul(int, int);
int dive(int, int);
void fun();
void cal(int(*pf)(int, int));
int main()
{
	int a = 0, b = 0, temp = 0, ret = 0;
	do
	{
		fun();
		cin >> temp;
		switch (temp)
		{
		case 1:
			cal(add);   //减少程序的冗余;
			break;
		case 2:
			cal(sub);
			break;
		case 3:
			cal(mul);
			break;
		case 4:
			cal(dive);
			break;
		}

	} while (temp);
}
void cal(int(*pf)(int,int))   //函数指针，形参为int类型，返回值为int，回调函数
{
	int x, y;
	cout << "Please Input two number:";
	cin >> x;
	cin >> y;
	cout << "result:" << pf(x, y) << endl;
}
void fun()
{
	cout << "**************************" << endl
		<< "***   1.add    2.sub   ***" << endl
		<< "**************************" << endl
		<< "***   3.mul    4.dive   ***" << endl
		<< "**************************" << endl;
}
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int dive(int a, int b)
{
	if (b == 0)
	{
		cout << "Error!" << endl;
	}
	else
	{
		return a / b;
	}
}