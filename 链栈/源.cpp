#include<iostream>
using std::cout;
using std::cin;
using std::endl;

typedef int Datatype;

typedef struct StackNode
{
	Datatype data;
	struct StackNode* next;
}StackNode, * pStackNode;

pStackNode InitStack()     //初始化链栈
{
	pStackNode s = (StackNode*)malloc(sizeof(StackNode));
	if (!s)
	{
		perror("InitStack malloc");
		return NULL;
	}
	s->next = NULL;
	return s;
}

int Push_Stack(StackNode* L, Datatype x)    //入栈
{
	pStackNode s = (StackNode*)malloc(sizeof(StackNode));
	if (!s)
	{
		perror("Push_Stack malloc");
		return 0;
	}
	s->data = x;
	s->next = L->next;
	L->next = s;
	return 1;
}

int Pop_Stack(StackNode* L, Datatype* ptr)
{
	if (!L)
	{
		perror("Pop_Stack");
		return 0;
	}
	StackNode* s = L->next;  //L->next 类似于线性表头指针的作用，该指针记录这栈顶元素的地址
	*ptr = s->data;
	L->next = s->next;    // L->next=L->next->next  
	free(s);
	return 1;
}

int Gettop_Stack(StackNode* L, Datatype* ptr)  //取栈顶元素
{
	if (!L)
	{
		perror("Gettop_Stack");
		return 0;
	}
	*ptr = L->next->data;
	return 1;
}

int Length_Stack(StackNode* L)   //求栈长
{
	if (!L)
	{
		perror("Length_Stack");
		return 0;
	}
	int count = 0;
	pStackNode s = L->next;
	while (s)
	{
		count++;
		s = s->next;
	}
	return count;
}

int Empty_Stack(StackNode* L)   //判断栈空
{
	if (!L->next)
	{
		return 1;  //栈为空
	}
	else
	{
		return 0;
	}
}

void main()
{
	int i, t, x, a[20];
	pStackNode top = InitStack();     //初始化栈
	x = Empty_Stack(top);       //判栈空结果赋值给X
	if (x = 0)
	{
		cout << "栈为空" << endl;
	}
	cout<<"请依次输入5个数,开始入栈;"<<endl;
	for (i = 0; i < 5; i++)
	{
		cin >> a[i];
		Push_Stack(top, a[i]);
		Gettop_Stack(top,&x);
		if (x != 1)
		{
			cout << "当前栈顶元素为:" << x << endl;
		}
	}
	cout<<"入栈结束" << endl;
	cout << "栈长为:" << Length_Stack(top) << endl;
	cout<<"开始出栈:";
	for (i = 0; i < 5; i++)
	{
		Pop_Stack(top, &t);
		cout<< t<<" ";
	}
	cout << endl << "出栈后栈长为:" << Length_Stack(top) << endl;
}