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

pStackNode InitStack()     //��ʼ����ջ
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

int Push_Stack(StackNode* L, Datatype x)    //��ջ
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
	StackNode* s = L->next;  //L->next ���������Ա�ͷָ������ã���ָ���¼��ջ��Ԫ�صĵ�ַ
	*ptr = s->data;
	L->next = s->next;    // L->next=L->next->next  
	free(s);
	return 1;
}

int Gettop_Stack(StackNode* L, Datatype* ptr)  //ȡջ��Ԫ��
{
	if (!L)
	{
		perror("Gettop_Stack");
		return 0;
	}
	*ptr = L->next->data;
	return 1;
}

int Length_Stack(StackNode* L)   //��ջ��
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

int Empty_Stack(StackNode* L)   //�ж�ջ��
{
	if (!L->next)
	{
		return 1;  //ջΪ��
	}
	else
	{
		return 0;
	}
}

void main()
{
	int i, t, x, a[20];
	pStackNode top = InitStack();     //��ʼ��ջ
	x = Empty_Stack(top);       //��ջ�ս����ֵ��X
	if (x = 0)
	{
		cout << "ջΪ��" << endl;
	}
	cout<<"����������5����,��ʼ��ջ;"<<endl;
	for (i = 0; i < 5; i++)
	{
		cin >> a[i];
		Push_Stack(top, a[i]);
		Gettop_Stack(top,&x);
		if (x != 1)
		{
			cout << "��ǰջ��Ԫ��Ϊ:" << x << endl;
		}
	}
	cout<<"��ջ����" << endl;
	cout << "ջ��Ϊ:" << Length_Stack(top) << endl;
	cout<<"��ʼ��ջ:";
	for (i = 0; i < 5; i++)
	{
		Pop_Stack(top, &t);
		cout<< t<<" ";
	}
	cout << endl << "��ջ��ջ��Ϊ:" << Length_Stack(top) << endl;
}