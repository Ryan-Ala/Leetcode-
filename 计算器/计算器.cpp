#include<iostream>
using namespace std;
int add(int,int);
int sub(int,int);
int mul(int,int);
int dive(int,int);
void fun();
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
			cout << "Please Input two number:";
			cin >> a;
			cin >> b;
			ret = add(a, b);
			cout << "result: " << ret << endl;
			break;
		case 2:
			cout << "Please Input two number:";
			cin >> a;
			cin >> b;
			ret = sub(a, b);
			cout << "result: " << ret << endl;
			break;
		case 3:
			cout << "Please Input two number:";
			cin >> a;
			cin >> b;
			ret = mul(a, b);
			cout << "result: " << ret << endl;
			break;
		case 4:
			cout << "Please Input two number:";
			cin >> a;
			cin >> b;
			ret = dive(a, b);
			cout << "result: " << ret << endl;
			break;
		}

	} while (temp);
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
	return a / b;
}