#include<iostream>
using namespace std;
int main()
{
	for (int j = 0; j <6; j++)
	{

		for (int i = 0; i <6 - j; i++)
		{
			cout << " ";
		}
		for (int k = 0; k < 2 * j + 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int j = 0; j < 7; j++)
	{
		for (int i = 0; i < j; i++)
		{
			cout << " ";
		}
		for (int k = 0; k < 13 - j * 2; k++)
		{
			cout << "*";
		}
		cout << endl;
	}

}