#include<iostream>
using namespace std;
void my_strcpy(char* arr, const char* brr)
{
	while (*arr != '\0')
		arr++;
	while (*arr++ = *brr++);
}
int main()
{
	char s1[20] = "hello ", s2[] = "world";  //s1字符数组的长度必须要足够长
	my_strcpy(s1, s2);
	cout << s1;
}