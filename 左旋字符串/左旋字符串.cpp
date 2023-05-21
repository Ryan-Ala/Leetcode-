#include<iostream>
#include<string>
using namespace std;
int function(char s1[], char s2[]);
int main()
{
	char s1[] = "AABCD", s2[] = "BCDAA";
	cout << function(s1,s2) << endl;
}
int function(char s1[],char s2[])
{
	int sz1 = strlen(s1), sz2 = strlen(s2);
	if (sz1 == sz2)
	{
		int i = 0;
		for (int i = 0; i < sz1; i++)
		{
			if (*s1 == *s2)
			{
				return 1;
			}
			else
			{
				char temp = s1[0], * p = s1, * q = p + 1;
				for (int j = 0; j < sz1 - 1; j++)
				{
					*p++ = *q++;
				}
				s1[sz1 - 1] = temp;
			}

		}
		if (i == sz1)
		{
			return 0;
		}
	}
	else
		return 0;
}