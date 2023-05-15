#include<iostream>
using namespace std;
char* my_strstr(char* arr,char* brr)
{
	char* ar = arr, * m = NULL,*cp;
	while (*ar)
	{
		m = ar;
		cp = brr;
		while (*ar == *cp && *ar && *cp)
		{
			ar++;
			cp++;
			if (*cp == '\0')
				return m;
		}
		ar = ++m;
	}
	return NULL;
}
int main()
{
	char s1[] = "aellovvvvv  ", s2[] = "lov";
	if (my_strstr != NULL)
		cout << my_strstr(s1, s2);
	else
		cout << "NULL";
}