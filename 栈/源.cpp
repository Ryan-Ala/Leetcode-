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
void InitStack(Stack* S)  //��ʼ��ջ
{
	S->top = -1;
}
int Push(Stack* S, Datatype x)  //��ջ
{
	if (S->top == Stacksize - 1)
	{
		cout << "������󣬲���ʧ��!" << endl;
		return 0;
	}
	S->data[++S->top] = x;
	cout << "��ջ�ɹ�!" << endl;
	return 1;
}
int Pop(Stack* S, Datatype* ptr)   //��ջ
{
	if (S->top == -1)
	{
		cout << "�������,��ջʧ��!" << endl;
		return 0;
	}
	*ptr = S->data[S->top--];
	cout << "��ջ�ɹ�!" << endl;
	return 1;
}
int Gettop(Stack* S, Datatype* ptr)
{
	if (S->top == -1)
	{
		cout << "�������,ȡջ������!" << endl;
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