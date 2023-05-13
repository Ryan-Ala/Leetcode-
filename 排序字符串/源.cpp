//�����ĸ�Ӣ�ľ��ӣ���������ĸ��˳�����������ĸ����ӡ�(����ʱ��������С6д)(������������ͬ������ĸ�����յڶ�����ĸ��˳����������ڶ�����ĸ˳����ͬ�����յ�������ĸ˳������..������[strcmp, ����ֱ��ʵ���ַ����ıȽ�
//	���ǲ���ʵ�֡������ִ�Сд���ıȽ�])��
//	��what a beautiful flower��
//	��Hello world��
//	��how are you��
//	��nice to meet you��
#include<iostream>
int my_strcmp(const char* arr, const char* brr)
{
	char a = *arr, b = *brr;
	int m = toupper(a), n = toupper(b);
	while (*arr == *brr || (char*)m == (char*)n)
	{
		if (*arr == '\0')
		{
			return 0;
		}
		arr++;
		brr++;
		a = *arr;
		b = *brr;
		m = toupper(a);
		n = toupper(b);
	}
	if ((char*)m > (char*)n)
		return 1;
	else
		return -1;
}
void Swap(const char** a, const char** b)
{
	const char* temp = *a;
	*a = *b;
	*b = temp;
}
void compear(const char** a, int numsize, const char** ptr)
{
	for (int i = 0; i < 4; i++)
	{
		*(ptr + i) = *(a + i);
	}
	for (int i = 0; i < numsize - 1; i++)
	{
		for (int j = 0; j < numsize - i - 1; j++)
		{
			if (my_strcmp(ptr[j], ptr[j + 1]) == -1)
			{
				Swap(&ptr[j], &ptr[j + 1]);
			}
		}
	}
}
int main()
{
	const char* arr[4] = { "what a beautiful flower","Hello world","how are you","nice to meet you" };
	const char* ptr[4];
	compear(arr, 4, ptr);
	for (int i = 0; i < 4; i++)
	{
		printf(ptr[i]);
		printf("\n");
	}
}