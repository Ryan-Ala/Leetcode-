#include<iostream>
using namespace std;
void my_strcat(char* arr, const char* brr)
{
	char* start = arr;
	while (*arr != '\0')
		arr++;
	while (*arr++ = *brr++);
}
int main()
{
	char s1[20] = "aellovvvvv  ", s2[] = "hello";
	my_strcat(s1, s2);
	cout << s1;
}