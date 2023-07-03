#include<iostream>
#define size 10
int main()
{
	for(int j=0;j<size;j++)
		{
			if (j == 0||j==1)
			{
				for (int k = 0; k < j + 1; k++)
					printf("%d", 1);
					printf("\n");
			}
			else
			{
				printf("%d",1);
				for (int i = 0; i < j -1; i++)
					printf("%d", j);
				printf("%d\n",1);
			}
		}
}