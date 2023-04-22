#include<iostream>
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
	first->next = NULL;  //ͷָ���next����Ϊ��ָ�룬��������
	return first;
}
int Empty(Node* first)        //��������пղ�����ֻ��Ҫ�ж��������Ƿ���ͷ�ڵ㣬
{
	if (first->next == NULL) 
	{                //������Ϊ�գ�����1
		return 1;
	}
	else
		return 0;
}
void PrintfList(Node* L)  //��������������
{
	Node* p = L->next;  //L->next�м�¼����node���͵ĵ�ַ���ʿ��Խ��丳ֵ��Node*��ָ��p;
	while (p != NULL)
	{
		std::cout<<p->data<<" ";
		p = p->next;
	}
}
int Length(Node* L)  //������ĳ���
{
	Node* p = L->next;
	int count = 0;    //int һ��������;
	while (p != NULL)
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
	while (p != NULL)
	{
		if (p->data == x)
			return count;
		count++;
		p = p->next;
	}
	return 0;  //��δ�ҵ����򷵻�0;
}
int Get(Node* L, int i, Datatype *ptr)   //��λ����,
{
	Node* p = L->next;        //����ָ��p��ʼ��
	int count = 1;        //�ۼ���
	while (p!=NULL&&count<i)
	{
		p = L->next;
		count++;
	}
	if (p == NULL)
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
	Node* s = NULL, * p = L;
	int count = 1;
	while (p!=NULL&&count<i)
	{
		p = L->next;
		count++;
	}
	if (p == NULL)
	{
		std::cout << "λ�ô��󣬲���ʧ��" << std::endl;
		return 0;
	}
	else
	{
		s =(Node*)malloc(sizeof(Node));       //��̬����һ��Node���͵��ڴ�
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
Node* CreatListtou(Datatype a[],int n)      //����������,ͷ�巨
{
	Node* L = (Node*)malloc(sizeof(Node));
	if (L == NULL)
	{
		perror("malloc:");
		return NULL;
	}
	L->next = NULL;      //��ʼ��ͷ�ڵ�
	Node* s = NULL;
	for(int i=0;i<n;i++)    //ͷ�巨
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
	r->next = NULL;
	return L;
}
int Delete(Node* L, int i, Datatype* ptr)   //ɾ������
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
		std::cout << "λ�ô���ɾ��ʧ��" << std::endl;   //ɾ������p��ָ�����һ���ڵ㣬������Ҫ�ж�p����һ���ڵ��Ƿ����
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
void DestroyList(Node* L)   //���ٵ�����
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