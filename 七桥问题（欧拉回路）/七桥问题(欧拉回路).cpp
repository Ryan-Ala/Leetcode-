#include<iostream>
using  namespace std;
int main()         //�������ŵĳ���>=2�����򲻴���ŷ����·
{
	int a[4][4] = { {0,1,2,2}, {1,0,1,1},{2,1,0,0},{2,1,0,0} },ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int temp = 0;
		for (int j = 0; j < 4; j++)
		{
			temp += a[i][j];
		}
		if (temp % 2 == 1)
			ret++;
	}
	if (ret >= 2)
		cout << "������ŷ����·";
}