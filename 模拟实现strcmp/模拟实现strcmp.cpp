#include<iostream>
using namespace std;
int my_strcmp(const char* arr, const char* brr)
{
	while (*arr == *brr)
	{
		if (*arr == '\0')
		{
			return 0;
		}
			arr++;
			brr++;
	}
	if (*arr > *brr)
		return 1;
	else
		return -1;
}
int main()
{
	char s1[20] = "aello", s2[] = "hello";
	cout<<my_strcmp(s1, s2);
}