#include<iostream>
int LorS();
int LorSs();
int main()
{
	if (LorS())
		std::cout << "С��" << std::endl;
	else
		std::cout << "���"<<std::endl;
	if (LorSs())
		std::cout << "С��" << std::endl;
	else
		std::cout << "���" << std::endl;
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
		