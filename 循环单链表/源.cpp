#include<iostream>
using std::cout;
using std::endl;

typedef int Datatype;

typedef struct Node        //������Ľṹ���壬������Ͻṹ�������ڽṹ������Ҫʹ�õ�
{
	Datatype data;
	struct Node* next;      //˳������ﲻ��Ҫ���֣�����������ṹ�嶨��ʱ����Ҫ�ṹ����
}Node;

Node* InitList()     //��ʼ������
{
	Node* first = (Node*)malloc(sizeof(Node));
	if (first == NULL)
	{
		perror("malloc:");
		return NULL;
	}
	first->next = first;  //ͷָ���next����Ϊͷָ���Լ�����ѭ��������****************************
	return first;
}

int Empty(Node* first)        //��������пղ�����ֻ��Ҫ�ж��������Ƿ���ͷ�ڵ㣬
{
	if (first->next == first)  //******************************
	{                //������Ϊ�գ�����1
		return 1;
	}
	else
		return 0;
}

void PrintfList(Node* L)  //��������������
{
	Node* p = L->next;  //L->next�м�¼����node���͵ĵ�ַ���ʿ��Խ��丳ֵ��Node*��ָ��p;
	while (p != L)          //********************************
	{
		std::cout << p->data << " ";
		p = p->next;
	}
}
int Length(Node* L)  //������ĳ���
{
	Node* p = L->next;
	int count = 0;    //int һ��������;
	while (p != L)         //************************************  
	{
		count++;
		p = p->next;
	}
	return count;
}
int Locate(Node* L, Datatype x)  //��ֵ����,����Ԫ������λ��
{
	Node* p = L->next;
	int count = 1;       //����������¼����Ԫ������λ�ã��ҵ�ʱ����
	while (p != L)    //************************************
	{
		if (p->data == x)
			return count;
		count++;
		p = p->next;
	}
	return 0;  //��δ�ҵ����򷵻�0;
}
int Get(Node* L, int i, Datatype* ptr)   //��λ����,
{
	Node* p = L->next;        //����ָ��p��ʼ��
	int count = 1;        //�ۼ���
	while (p != L && count < i)  //***********************
	{
		p = L->next;
		count++;
	}
	if (p == L)  //*****************************
	{
		std::cout << "λ�ô��󣬲���ʧ��" << std::endl;
		return 0;
	}
	else
	{
		*ptr = L->data;
		return 1;
	}
}
int Insert(Node* L, int i, Datatype x)   //�������,��ͨ����
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
		std::cout << "λ�ô��󣬲���ʧ��" << std::endl;
		return 0;
	}
	else
	{
		s = (Node*)malloc(sizeof(Node));       //��̬����һ��Node���͵��ڴ�
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
Node* CreatListtou(Datatype a[], int n)      //����������,ͷ�巨
{
	Node* L = (Node*)malloc(sizeof(Node));
	if (L == NULL)
	{
		perror("malloc:");
		return NULL;
	}
	L->next = L;      //��ʼ��ͷ�ڵ�****************************
	Node* s = NULL;
	for (int i = 0; i < n; i++)    //ͷ�巨
	{
		s = (Node*)malloc(sizeof(Node));
		if (s == NULL)
		{
			perror("malloc:");
			return NULL;
		}
		s->data = a[i];       //Ϊÿ������Ԫ�ؽ���һ�����
		s->next = L->next;    //���ڵ�s���뵽ͷ�ڵ�֮��
		L->next = s;
	}
	return L;
}
Node* CreatListwei(Datatype a[], int n)      //����������,β�巨
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
		r->next = s;       //r��ָ����ڴ�ռ����洢����һ���ռ�ĵ�ַ���޸�Ϊ��ǰ��malloc�ĵ�ַ
		r = s;             //rָ��ǰ��malloc�ĵ�ַ	
	}
	r->next = L;  //ѭ���������޸�**********************************
	return L;
}

//CreatListwei����
void CreatListwei(Node* &L,Datatype a[], int n)   //β�巨����һ��д��,�������õķ�ʽ
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
		r->next = s;       //r��ָ����ڴ�ռ����洢����һ���ռ�ĵ�ַ���޸�Ϊ��ǰ��malloc�ĵ�ַ
		r = s;             //rָ��ǰ��malloc�ĵ�ַ	
	}
	r->next = L;
}
int Delete(Node* L, int i, Datatype* ptr)   //ɾ������
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
		std::cout << "λ�ô���ɾ��ʧ��" << std::endl;   //ɾ������p��ָ�����һ���ڵ㣬������Ҫ�ж�p����һ���ڵ��Ƿ����
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
void DestroyList(Node* L)   //���ٵ�����
{
	Node* p = L;
	while (L != p)     //ѭ���������޸�********************************
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