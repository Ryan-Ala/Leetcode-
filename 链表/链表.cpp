#include<iostream>
typedef int Datatype;
typedef struct Node        //单链表的结构定义，这里加上结构体名，在结构体中需要使用到
{
	Datatype data;
	struct Node* next;      //顺序表这里不需要名字，所以在上面结构体定义时不需要结构体名
}Node;
Node* InitList()     //初始化链表
{
	Node* first = (Node*)malloc(sizeof(Node));
	if (first == NULL)
	{
		perror("malloc:");
		return NULL;
	}
	first->next = NULL;  //头指针的next设置为空指针，即空链表
	return first;
}
int Empty(Node* first)        //单链表的判空操作，只需要判定单链表是否有头节点，
{
	if (first->next == NULL) 
	{                //单链表为空，返回1
		return 1;
	}
	else
		return 0;
}
void PrintfList(Node* L)  //单链表的历遍操作
{
	Node* p = L->next;  //L->next中记录的是node类型的地址，故可以将其赋值给Node*的指针p;
	while (p != NULL)
	{
		std::cout<<p->data<<" ";
		p = p->next;
	}
}
int Length(Node* L)  //求单链表的长度
{
	Node* p = L->next;
	int count = 0;    //int 一个计数器;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}
int Locate(Node* L, Datatype x)  //按值查找,返回元素所在位置
{
	Node* p = L->next;
	int count = 1;       //计数器，记录查找元素所在位置，找到时返回
	while (p != NULL)
	{
		if (p->data == x)
			return count;
		count++;
		p = p->next;
	}
	return 0;  //若未找到，则返回0;
}
int Get(Node* L, int i, Datatype *ptr)   //按位查找,
{
	Node* p = L->next;        //工作指针p初始化
	int count = 1;        //累加器
	while (p!=NULL&&count<i)
	{
		p = L->next;
		count++;
	}
	if (p == NULL)
	{
		std::cout << "位置错误，查找失败" << std::endl;
		return 0;
	}
	else
	{
		*ptr = L->data;
		return 1;
	}
}
int Insert(Node* L, int i, Datatype x)   //插入操作,普通插入
{
	Node* s = NULL, * p = L;
	int count = 1;
	while (p!=NULL&&count<i)
	{
		p = L->next;
		count++;
	}
	if (p == NULL)
	{
		std::cout << "位置错误，插入失败" << std::endl;
		return 0;
	}
	else
	{
		s =(Node*)malloc(sizeof(Node));       //动态分配一块Node类型的内存
		if (s == NULL)
		{
			perror("malloc:");
			return 0;
		}
		s->data = x;
		s->next = p->next;
		p->next = s;
		return 1;
	}
}
Node* CreatListtou(Datatype a[],int n)      //建立单链表,头插法
{
	Node* L = (Node*)malloc(sizeof(Node));
	if (L == NULL)
	{
		perror("malloc:");
		return NULL;
	}
	L->next = NULL;      //初始化头节点
	Node* s = NULL;
	for(int i=0;i<n;i++)    //头插法
	{
		s = (Node*)malloc(sizeof(Node));
		if (s == NULL)
		{
			perror("malloc:");
			return NULL;
		}
		s->data = a[i];       //为每个数组元素建立一个结点
		s->next = L->next;    //将节点s插入到头节点之后
		L->next = s;  
	}
	return L;
}
Node* CreatListwei(Datatype a[], int n)      //建立单链表,尾插法
{
	Node* L = (Node*)malloc(sizeof(Node));
	if (L == NULL)
	{
		perror("malloc:");
		return NULL;
	}
	L->next = NULL;
	Node* s = NULL, * r = L;
	for (int i = 0; i < n; i++)
	{
		s = (Node*)malloc(sizeof(Node));
		if (s == NULL)
		{
			perror("malloc:");
			return NULL;
		}
		s->data = a[i];
		r->next = s;       //r所指向的内存空间所存储的下一个空间的地址被修改为当前新malloc的地址
		r = s;             //r指向当前新malloc的地址	
	}
	r->next = NULL;
	return L;
}
int Delete(Node* L, int i, Datatype* ptr)   //删除操作
{
	Node* p = L, * q = NULL;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL && p->next == NULL)
	{
		std::cout << "位置错误，删除失败" << std::endl;   //删除的是p所指向的下一个节点，所以需要判断p的下一个节点是否存在
		return 0;
	}
	else
	{
		q = p->next;
		*ptr = q->data;
		p->next = q->next;
		free(q);
		return 1;
	}
}
void DestroyList(Node* L)   //销毁单链表
{
	Node* p = L;
	while (L != NULL)
	{
		L = L->next;
		free(p);
		p = L;
	}
}
int main()
{
	int r[5] = { 1,2,3,4,5 };
	Node* first = InitList();
	first = CreatListwei(r, 5);
	PrintfList(first);
}