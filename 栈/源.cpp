#include<iostream>
using std::cout;
using std::endl;
#define Stacksize 4
typedef int Datatype;
typedef struct Stack
{
	Datatype data[Stacksize];
	int top;
}Stack;
void InitStack(Stack* S)  //³õÊ¼»¯Õ»
{
	S->top = -1;
}
int Push(Stack* S, Datatype x)  //ÈëÕ»
{
	if (S->top == Stacksize - 1)
	{
		cout << "ÉÏÒç´íÎó£¬²åÈëÊ§°Ü!" << endl;
		return 0;
	}
	S->data[++S->top] = x;
	cout << "ÈëÕ»³É¹¦!" << endl;
	return 1;
}
int Pop(Stack* S, Datatype* ptr)   //³öÕ»
{
	if (S->top == -1)
	{
		cout << "ÏÂÒç´íÎó,³öÕ»Ê§°Ü!" << endl;
		return 0;
	}
	*ptr = S->data[S->top--];
	cout << "³öÕ»³É¹¦!" << endl;
	return 1;
}
int Gettop(Stack* S, Datatype* ptr)
{
	if (S->top == -1)
	{
		cout << "ÏÂÒç´íÎó,È¡Õ»¶¥´íÎó!" << endl;
		return 0;
	}
	*ptr = S->data[S->top];
	return 1;
}
int Empty(Stack* S)
{
	if (S->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	Stack con;
	InitStack(&con);
	int arr[] = { 1,2,3,4 },a=0;
	for (int i = 0; i < 4; i++)
	{
		Push(&con, arr[i]);
	}
	cout << Gettop(&con, &a) << "  " << a << endl << Empty(&con);
	for (int i = 0; i < 4; i++)
	{
		cout << Pop(&con, &a) << "  " << a << endl;
	}
}