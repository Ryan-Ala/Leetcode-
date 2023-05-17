#include<iostream>
#define size 20
int main()
{
	int sum = size, j = 0;
	for (int i = size; i >=0;)
	{
		i /= 2;
		sum += i;
		i = i + j;
		j = i % 2;
		if (i == 1)
			break;
	}
	std::cout << sum << std::endl;
}