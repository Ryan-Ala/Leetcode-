#include<iostream>
void Swap(char* a, char* b, int width)
{
	for (int i = 0; i < width; i++)
	{
		char temp = *a;
		*a = *b;
		*b = temp;
		a++;
		b++;
	}
}
void R_qsort(void* arr, size_t num, size_t width, int (*cmp)(const void* a, const void* b))//void fun(const void* a,const void* b)
{                                                                                //{ return  *(int*)a - *(int*)b;}
	


	for (int i = 0; i < num-1; i++)
	{
		int sum = 1;
		for (int j = 0; j < num -1- i; j++)
		{


			if (cmp((char*)arr+j*width,(char*)arr+(j+1)*width)>0)      //(char*)��ȡһ�����ݵ���ǰ��1�ֽڵĵ�ַ���ٽ��õ�ַ�������ص��������ص�����������Ӧ�����ͽ��н����ã����κ��������Ͷ��ܽ��д����Ч��
			{
				sum = 0;
				Swap((char*)arr+j*width,(char*)arr+(j+1)*width,width);
			}   //ͬ��ȡ��һ���ֽڵĵ�ַ���д��䣬��Swap������һ�ֽ�һ�ֽڵĽ��н������ﵽ�����������Ͷ�������Ч��
		}
		if (sum == 1)
		{
			break;   //�Ż�����
		}

	} 
}

int function(const void* a, const void* b)
{
	return *(double*) a -*(double*) b;         //����Ҫ�����������͵ĸı���ı�
}

int main()
{
	double arr[5] = { 1.234,3.21,43.2,23.02,2.1 };
	//int arr[5] = {2,5,7,1,9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	R_qsort(arr,sz,sizeof(arr[0]),function);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << "  ";
	}
}
//
