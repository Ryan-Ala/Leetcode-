#include"ListNode.h"

pListNode Init_List()
{
	pListNode s = (pListNode)malloc(sizeof(ListNode));
	if (!s)
	{
		cerr << ":)  ERROR!    Dynamic allocation of memory failed" << endl;
		exit(1);
	}
	s->next = s;
	s->prev = s;
	return s;
}

pListNode Buy_newNode()
{
	pListNode newnode = (pListNode)malloc(sizeof(ListNode));
	if (!newnode)
	{
		cerr << ":)  ERROR!    Dynamic allocation of memory failed" << endl;
		exit(1);
	}
	scanf_peoinform(&newnode->data);
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

pListNode Buy_newNode(peoinform* x)
{
	pListNode newnode = (pListNode)malloc(sizeof(ListNode));
	if (!newnode)
	{
		cerr << ":)  ERROR!    Dynamic allocation of memory failed" << endl;
		exit(1);
	}
	strcpy(newnode->data.name, x->name);
	strcpy(newnode->data.sex, x->sex);
	strcpy(newnode->data.tele, x->tele);
	strcpy(newnode->data.address, x->address);
	strcpy(newnode->data.realation, x->realation);
	newnode->data.age = x->age;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

void Insert_List(pListNode L)
{
	if (!L)
	{
		cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		exit(1);
	}
	pListNode prev = L->prev;
	pListNode newNode = Buy_newNode();
	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = L;
	L->prev = newNode;
}

void Insert_End(pListNode L)
{
	if (!L)
	{
		cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		exit(1);
	}
	Insert_List(L);
}

void Insert_End(pListNode L, pListNode x)
{
	if (!L)
	{
		cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		exit(1);
	}
	if (!x)
	{
		cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		exit(1);
	}
	pListNode prev = L->prev;
	prev->next = x;
	x->prev = prev;
	x->next = L;
	L->prev = x;
}

void Insert_Head(pListNode L)
{
	if (!L)
	{
		cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		exit(1);
	}
	Insert_List(L->next);
}

void Delete_End(pListNode L)
{
	if (!L)
	{
		cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		exit(1);
	}
	if (Empty_List(L))
	{
		exit(1);
	}
	Delete(L->prev);  
}

void Delete_Head(pListNode L)
{
	if (!L)
	{
		cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		exit(1);
	}
	if (Empty_List(L))
	{
		exit(1);
	}
	Delete(L->next);
}

void Printf_List(pListNode L)
{
	if (!L)
	{
		cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		exit(1);
	}
	pListNode s = L->next;
	cout << "表中元素为:";
	while (s != L)
	{
		cout << "姓名:" << s->data.name << "   ";
		cout << "性别:" << s->data.sex << "   ";
		cout << "年龄:" << s->data.age << "   ";
		cout << "电话:" << s->data.tele << "   ";
		cout << "地址:" << s->data.address << "   ";
		cout << "关系:" << s->data.realation << "   ";
		s = s->next;
	}
	cout << endl << "打印完毕!" << endl;
}

pListNode Find_List(pListNode L, const char* x)
{
	if (!L)
	{
		cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		return NULL;
	}
	pListNode s = L->next;
	while (s != L)
	{
		if (!strcmp(s->data.name,x))
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
		return NULL;
	}
	return NULL;
}

int Delete(pListNode s)
{
	if (!s)
	{
		cerr << "Delete_L_NULL" << endl;
		exit(1);
	}
	s->prev->next = s->next;
	s->next->prev = s->prev;
	free(s);
	s = NULL;
	return 1;
}

int Delete_List(pListNode L, const char* x)
{
	if (!L)
	{
		cerr << "Delete_L_NULL" << endl;
		exit(1);
	}
	pListNode s = Find_List(L, x);
	if (!s)
	{
		cerr << "删除失败!" << endl;
		return 0;
	}
	return Delete(s);
}

int Destory_List(pListNode L)  
{
	if (!L)
	{
		cerr << "Destory_L_NULL" << endl;
		exit(1);
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
	if (!L)
	{
		cerr << "Empty_List_L_NULL" << endl;
		exit(1);
	}
	return L->next == L;
}

int Length_List(pListNode L)
{
	if (!L)
	{
		cerr << "Length_L_NULL" << endl;
		exit(1);
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


