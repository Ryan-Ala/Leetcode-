#include"ListNode.h"

ListNode* Init_List()
{
	pListNode s = (pListNode)malloc(sizeof(ListNode));
	if (!s)
	{
		perror("Init_List");
		return NULL;
	}
	s->next = s;
	s->prev = s;
	return s;
}

void Insert_End(ListNode* L, Datatype x)  //β�巨
{
	if (!L)
	{
		perror("Inser_End_L_NULL");
		return;
	}
	pListNode s = (ListNode*)malloc(sizeof(ListNode));
	if (!s)
	{
		perror("Insert_End_malloc");
		return;
	}
	s->data = x;
	s->next = L;
	s->prev = L->prev;
	L->prev->next = s;
	L->prev = s;
}

void Insert_Head(ListNode* L, Datatype x)   //ͷ�巨
{
	if (!L)
	{
		perror("Inser_Head_L_NULL");
		return;
	}
	pListNode s = (ListNode*)malloc(sizeof(ListNode));
	if (!s)
	{
		perror("Insert_End_malloc");
		return;
	}
	s->data = x;
	s->next = L->next;
	s->prev = L;
	L->next->prev = s;
	L->next = s;
}

void Printf_List(pListNode L)   //��ӡ
{
	if (!L)
	{
		perror("Printf_L_NULL");
		return;
	}
	pListNode s = L->next;
	cout << "����Ԫ��Ϊ:";
	while (s != L)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl << "��ӡ���!" << endl;
}

pListNode Find_List(pListNode L,Datatype x)   //��ֵ����
{
	if (!L)
	{
		perror("Find_L_NULL");
		return NULL;
	}
	pListNode s = L->next;
	while (s != L)
	{
		if (s->data == x)
		{
			return s;
		}
		else
		{
			s = s->next;
		}
	}
	if (s = L)
	{
		cout << "Can't find " << x << " in List!" << endl;
	}
	return NULL;
}

int Insert_List(pListNode L, Datatype x,int i)   //����λ�ò���
{
	if (!L)
	{
		perror("Insert_L_NULL");
		return 0;
	}
	if (i < 1)
	{
		cout << "����λ�ô���!" << endl;
		return 0;
	}
	pListNode s = (ListNode*)malloc(sizeof(ListNode));
	if (!s)
	{
		perror("Insert_malloc");
		return 0;
	}
	int count = 1;
	pListNode r = L->next;
	while (r != L && count < i)
	{
		r = r->next;
		count++;
	}
	if (r == L && count == i)  //�������
	{
		Insert_End(L, x);  //β�巨
	}
	else
	{
		s->data = x;
		s->next = r;
		s->prev = r->prev;
		r->prev->next = s;
		r->prev = s;
	}
	return 1;
}

int Delete_(pListNode s)  //ɾ��ĳһλ�õ�Ԫ��
{
	if (!s)
	{
		perror("Delete_L_NULL");
		return 0;
	}
	s->prev->next = s->next;
	s->next->prev = s->prev;
	free(s);
	s = NULL;
	return 1;
}

int Delete_List(pListNode L, Datatype x)  //ɾ��ĳ��Ԫ��
{
	if (!L)
	{
		perror("Delete_L_NULL");
		return 0;
	}
	pListNode s = Find_List(L, x);
	if (!s)
	{
		cout << "ɾ��ʧ��!" << endl;
		return 0;
	}
	if (Delete_(s))
		return 1;
	else
		return 0;
}

int Destory_List(pListNode L)  //����ѭ��˫����
{
	if (!L)
	{
		perror("Destory_L_NULL");
		return 0;
	}
	pListNode s = L->next, r = s;
	while (s != L)
	{
		s = s->next;
		free(r);
		r = s;
	}
	free(L);
	L = NULL;
	return 1;
}

int Empty_List(pListNode L)
{
	if (L->next == L)
	{
		cout << "The list is empty!" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}
int Length_List(pListNode L)
{
	if (!L)
	{
		perror("Length_L_NULL");
		return 0;
	}
	int count = 0;
	pListNode s = L->next;
	while (s != L)
	{
		count++;
		s = s->next;
	}
	return count;
}