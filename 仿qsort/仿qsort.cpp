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


			if (cmp((char*)arr+j*width,(char*)arr+(j+1)*width)>0)      //(char*)将取一个数据的最前面1字节的地址，再将该地址传输至回调函数，回调函数再用相应的类型进行解引用，起到任何数据类型都能进行传输的效果
			{
				sum = 0;
				Swap((char*)arr+j*width,(char*)arr+(j+1)*width,width);
			}   //同样取第一个字节的地址进行传输，在Swap函数内一字节一字节的进行交换，达到各个数据类型都交换的效果
		}
		if (sum == 1)
		{
			break;   //优化程序
		}

	} 
}

int function(const void* a, const void* b)
{
	return *(double*) a -*(double*) b;         //这里要随这数据类型的改变而改变
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
