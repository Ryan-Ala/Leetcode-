#include<iostream>
using namespace std;
int main()
{
	int a[4][4] = { {1,5,7,9},{4,6,10,15}, {4,11,12,19},{14,16,18,21} }, i = 0, j = 3, m= 12;
	while (a[i][j] != m)
	{
		if (a[i][j] > m)
		{
			j--;
		}
		else if(a[i][j] < m)
		{
			i++;
		}
        if (a[i][j] == m)
		{
			cout << "´æÔÚ" << endl;
			break;
		}
		if (i >3 ||j < 0)
		{
			cout << "²»´æÔÚ";
			break;
		}
	}
}