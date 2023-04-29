#include<iostream>
void reserve(char* start, char* p)
{
	while (start < p)
	{
		char temp = *start;
		*start = *p;
		*p = temp;
		start++;
		p--;
	}
}
int main()
{
	char arr[] = "wang like ming.";
	int len = strlen(arr);
	reserve(arr,arr+len-1);
	char* cur = arr;
	while (*cur)
	{
		char* start = cur;
		while (*cur != ' ' && *cur != '\0')
		{
			cur++;
		}
		reserve(start, cur - 1);
		if (*cur == ' ')
		{
			cur++;
		}
	}
	std::cout << arr << std::endl;
}