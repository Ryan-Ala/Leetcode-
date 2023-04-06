#include<iostream>
#include<assert.h>
void* my_memmove(void* direction, void* source, size_t number)
{
	void* direct = direction;
	assert(direction, source);//�ж��Ƿ�Ϊ��ָ��
	if (direction < source)//Ŀ���ַ��Դ��ַǰ�����ô�ǰ����(��source��ǰ���Ԫ�ؿ�ʼ����)һ���ֽ�һ���ֽڽ��и���
	{
		for(int i=0;i<number;i++)
		{
			*((char*)direction+i) = *((char*)source+i);
		}
	}
	else//Ŀ���ַ��Դ��ַ�󣬲��ôӺ���ǰ(��source������Ԫ�ؿ�ʼ����)һ���ֽ�һ���ֽڽ��и���
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