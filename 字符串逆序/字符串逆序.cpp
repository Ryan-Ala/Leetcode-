#include<iostream>
#include<assert.h>
void nixu(char*);
int main()
{
	char arr[] = "ip like ni.";
	nixu(arr);
	std::cout << arr << std::endl;
}
void nixu(char arr[])
{
	//assert(arr == NULL); //ip like ni.   //.in ekil pi   //ni. like ip
	char* p = arr, * q = p;
	while (*q++ != '\0')
		;
	q-=2;
	while (p < q)
	{
		char temp;
		temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}
	p = q = &arr[0];
	while (*q != '\0')
	{
		while (*q != ' '&&*q!='\0')
		{
			
			q++;
		}
		char* k = q;
		q--;
		while (p < q)
		{
			char temp;
			temp = *p;
			*p = *q;
			*q = temp;
			p++;
			q--;
		}
		if (*k == '\0')
			break;
		q = ++k;
		p = q;
	}
}
