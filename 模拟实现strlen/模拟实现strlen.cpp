#include<iostream>
int my_strlen(const char* arr)
{
	int count = 0;
	while (*arr++ != '\0')
		count++;
	return count;
}
int main()
{
	char s[] = "abcdefg";
	std::cout << my_strlen(s);
}