#include<iostream>
using std::cout;
using std::endl;
using std::cin;

typedef int Datatype;

typedef struct Node   //链队的基本存储结构定义
{
	Datatype data;
	struct Node* next;
}Node, * pNode;

typedef struct LinkQueue  //链队相关工作指针的定义
{
	pNode front, rear;
}LinkQueue, * pLinkQueue;

pLinkQueue InitQueue()   //初始化链队
{
	pLinkQueue a = (pLinkQueue)malloc(sizeof(LinkQueue));
	if (!a)
	{
		perror("InitQueue_malloc_LinkQueue_error!");
		return NULL;
	}
	pNode s = (pNode)malloc(sizeof(Node));
	if (!s)
	{
		perror("InitQueue_malloc_Node_error!");
		return NULL;
	}
	a->front = a->rear = s;
	return a;
}

int EnQueue(pLinkQueue L,Datatype x)    //入队列
{
	if (!L)
	{
		perror("EnQueue_pLinkQueue_is_NULL!");
		return 0;
	}
	pNode s = (pNode)malloc(sizeof(Node));
	if (!s)
	{
		perror("EnQueue_malloc_error!");
		return 0;
	}
	s->data = x;
	s->next = NULL;
	L->rear->next = s;
	L->rear = s;
	return 1;
}

int OutQueue(pLinkQueue L, Datatype* ptr)   //出队列
{
	if (!L)
	{
		perror("OutQueue_pLinkQueue_is_NULL!");
		return 0;
	}
	*ptr = L->front->next->data;
	pNode s = L->front->next;
	L->front->next = s->next;
	if (s->next == NULL)   //若满足改条件，说明队列已经是空
	{
		L->rear = L->front;
	}
	free(s);
	s = NULL;
	return 1;
}

int EmptyQueue(pLinkQueue L)  //判空
{
	if (!L)
	{
		perror("EmptyQueue_pLinkQueue_is_NULL!");
		return 0;
	}
	if (L->rear == L->front)
	{
		cout << "Node_already_empty!" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

int GetQueueHead(pLinkQueue L, Datatype* ptr)   //取队头
{
	if (!L)
	{
		perror("GetQueueHead_pLinkQueue_is_NULL!");
		return 0;
	}
	*ptr = L->front->next->data;
	return 1;
}

int DestoryQueue(pLinkQueue L)
{
	if (!L)
	{
		perror("Destory_pLinkQueue_is_NULL!");
		return 0;
	}
	pNode s = L->front;
	while (!s)
	{
		L->front =s->next;
		free(s);
		s = L->front;
	}
	s = NULL;
	return 1;
}

int main()
{
	LinkQueue* con = InitQueue();
	cout << EmptyQueue(con);
	for (int i = 0; i < 5; i++)
	{
		EnQueue(con, i);
	}
	int a;
	GetQueueHead(con, &a);
	cout << a << endl;
	cout << EmptyQueue(con) << endl;
	for (int i = 0; i < 5; i++)
	{
		OutQueue(con, &a);
		cout << a << endl;
	}
	cout << EmptyQueue(con);
	DestoryQueue(con);
}