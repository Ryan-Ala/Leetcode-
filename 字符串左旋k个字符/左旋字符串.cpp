#include<iostream>
#include<assert.h>
void zuoxuan(char* arr, int k);
int main()
{
	char arr[] = "abcdefg";
	zuoxuan(arr, 3);
	std::cout << arr << std::endl;
}
void zuoxuan(char* arr, int k)
{
	assert(arr);
	char* start = arr;
	int i=0;
	while (*(start+i))
		i++;
	for (int j = 0; j < k; j++)   //m   m    m    m m
	{                              //s   q
		char temp= *start;
		for (int m = 0; m < i-1; m++)
		{
			*(start + m) = *(start+1+m);
		}
		*(start+i-1)= temp;
	}
}