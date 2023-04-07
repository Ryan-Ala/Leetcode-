#include<iostream>
#include<assert.h>
void* my_memcpy(void* direction,void *source,size_t number)
{
	void* direct = direction;
	assert(direction, source);   //判断是否为空指针
	while (number--)
	{
		*(char*)direction = *(char*)source;  //用指针类型强制转换，以最小的单位一字节一字节的进行cpoy
		direction = (char*)direction + 1;   //强制转换为指针类型后  字节+1
		source = (char*)source + 1;
	}
	return direct;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int brr[10] = { 0 };
	my_memcpy(brr, arr, 24);
	for (int i = 0; i < 10; i++)
	{
		std::cout << brr[i] << " ";
	}
}