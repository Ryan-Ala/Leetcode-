#include<iostream>
using std::cout;
using std::endl;

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
	first->next = first;  //头指针的next设置为头指针自己，即循环单链表****************************
	return first;
}

int Empty(Node* first)        //单链表的判空操作，只需要判定单链表是否有头节点，
{
	if (first->next == first)  //******************************
	{                //单链表为空，返回1
		return 1;
	}
	else
		return 0;
}

void PrintfList(Node* L)  //单链表的历遍操作
{
	Node* p = L->next;  //L->next中记录的是node类型的地址，故可以将其赋值给Node*的指针p;
	while (p != L)          //********************************
	{
		std::cout << p->data << " ";
		p = p->next;
	}
}
int Length(Node* L)  //求单链表的长度
{
	Node* p = L->next;
	int count = 0;    //int 一个计数器;
	while (p != L)         //************************************  
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
	while (p != L)    //************************************
	{
		if (p->data == x)
			return count;
		count++;
		p = p->next;
	}
	return 0;  //若未找到，则返回0;
}
int Get(Node* L, int i, Datatype* ptr)   //按位查找,
{
	Node* p = L->next;        //工作指针p初始化
	int count = 1;        //累加器
	while (p != L && count < i)  //***********************
	{
		p = L->next;
		count++;
	}
	if (p == L)  //*****************************
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
	int length = Length(L);
	if (length + 1 == i)
	{
		Node* s = (Node*)malloc(sizeof(Node)), * p = L;
		while (length--)
		{
			p = p->next;
		}
		s->data = x;
		s->next = L;
		p->next = s;
		return 1;
	}
	Node* s = NULL, * p = L->next, * r = L;  //**************
	int count = 1;
	while (p != L && count < i)//*********************
	{
		r = r->next;
		p = p->next;
		count++;
	}
	if (p == L)//*********************************
	{
		std::cout << "位置错误，插入失败" << std::endl;
		return 0;
	}
	else
	{
		s = (Node*)malloc(sizeof(Node));       //动态分配一块Node类型的内存
		if (s == NULL)
		{
			perror("malloc:");
			return 0;
		}
		s->data = x;
		s->next = p;
		r->next = s;
		return 1;
	}
}
Node* CreatListtou(Datatype a[], int n)      //建立单链表,头插法
{
	Node* L = (Node*)malloc(sizeof(Node));
	if (L == NULL)
	{
		perror("malloc:");
		return NULL;
	}
	L->next = L;      //初始化头节点****************************
	Node* s = NULL;
	for (int i = 0; i < n; i++)    //头插法
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
	r->next = L;  //循环单链表修改**********************************
	return L;
}

//CreatListwei重载
void CreatListwei(Node* &L,Datatype a[], int n)   //尾插法的另一种写法,采用引用的方式
{
	L = (Node*)malloc(sizeof(Node));
	if (L == NULL)
	{
		perror("malloc:");
		return;
	}
	L->next = NULL;
	Node* s = NULL, * r = L;
	for (int i = 0; i < n; i++)
	{
		s = (Node*)malloc(sizeof(Node));
		if (s == NULL)
		{
			perror("malloc:");
			return;
		}
		s->data = a[i];
		r->next = s;       //r所指向的内存空间所存储的下一个空间的地址被修改为当前新malloc的地址
		r = s;             //r指向当前新malloc的地址	
	}
	r->next = L;
}
int Delete(Node* L, int i, Datatype* ptr)   //删除操作
{
	Node* p = L->next, * r = L;
	int count = 1;
	while (p != L && count < i )
	{
		r = r->next;
		p = p->next;
		count++;
	}
	if (p == L && p->next == L)
	{
		std::cout << "位置错误，删除失败" << std::endl;   //删除的是p所指向的下一个节点，所以需要判断p的下一个节点是否存在
		return 0;
	}
	else
	{
		*ptr = p->data;
		r->next = p->next;
		free(p);
		return 1;
	}
}
void DestroyList(Node* L)   //销毁单链表
{
	Node* p = L;
	while (L != p)     //循环单链表修改********************************
	{
		L = L->next;
		free(p);
		p = L;
	}
}
int main()
{
	int r[5] = { 1,2,3,4,5 };
	Node* first;
	first = CreatListwei(r, 5);
	PrintfList(first);
	cout << endl << Length(first) << endl;
	Insert(first, 6, 100);
	PrintfList(first);
	int a = 0;
	Delete(first, 1, &a);
	cout << endl;
	PrintfList(first);
	cout << endl << a << endl << Length(first);

}