#include<iostream>
int LorS();
int LorSs();
int main()
{
	if (LorS())
		std::cout << "小端" << std::endl;
	else
		std::cout << "大端"<<std::endl;
	if (LorSs())
		std::cout << "小端" << std::endl;
	else
		std::cout << "大端" << std::endl;
}
int LorS()
{
	int a = 1;
	return *(char*)&a;
}
int LorSs()
{
	union ab
	{
		int a;
		char b;
	}ls;
	ls.a = 1;
	return ls.b;
}
		