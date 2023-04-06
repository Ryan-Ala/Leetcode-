#include<iostream>
#include<assert.h>
void* my_memmove(void* direction, void* source, size_t number)
{
	void* direct = direction;
	assert(direction, source);//判断是否为空指针
	if (direction < source)//目标地址在源地址前，采用从前往后(从source最前面的元素开始复制)一个字节一个字节进行复制
	{
		for(int i=0;i<number;i++)
		{
			*((char*)direction+i) = *((char*)source+i);
		}
	}
	else//目标地址在源地址后，采用从后往前(从source最后面的元素开始复制)一个字节一个字节进行复制
	{
		while (number--)
		{
			*((char*)direction + number) = *((char*)source + number);
		}
	}
	return direct;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,177,18,19,20 };
	my_memmove(arr, arr+5, 40);
	for (int i = 0; i < 20; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	/*my_memmove(arr + 10, arr, 40);
	for (int i = 0; i < 20; i++)
	{
		std::cout << arr[i] << " ";
	}*/
}