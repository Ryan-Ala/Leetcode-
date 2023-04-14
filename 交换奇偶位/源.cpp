#include<iostream>

#define SWAP(x) (x=((x&0x55555555)<<1)+((x&0xaaaaaaaa)>>1))

int main()
{
	int a = 100;
	SWAP(a);
	std::cout << a << std::endl;
}