#include<iostream>
#include<assert.h>
void* my_memcpy(void* direction,void *source,size_t number)
{
	void* direct = direction;
	assert(direction, source);   //�ж��Ƿ�Ϊ��ָ��
	while (number--)
	{
		*(char*)direction = *(char*)source;  //��ָ������ǿ��ת��������С�ĵ�λһ�ֽ�һ�ֽڵĽ���cpoy
		direction = (char*)direction + 1;   //ǿ��ת��Ϊָ�����ͺ�  �ֽ�+1
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