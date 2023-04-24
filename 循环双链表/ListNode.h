#pragma once
#include<iostream>
using std::cout;
using std::endl;
typedef int Datatype;

typedef struct ListNode
{
	Datatype data;
	struct ListNode* next;
	struct ListNode* prev;   //ָ����һ���ڵ�
}ListNode, * pListNode;

ListNode* Init_List();

void Insert_End(ListNode* L, Datatype x); //β�巨

void Insert_Head(ListNode* L, Datatype x);   //ͷ�巨

void Printf_List(pListNode L);   //��ӡ

pListNode Find_List(pListNode L, Datatype x);   //��ֵ����

int Insert_List(pListNode L, Datatype x, int i);   //����λ�ò���

int Delete_(pListNode s);  //ɾ��ĳһλ�õ�Ԫ��

int Delete_List(pListNode L, Datatype x);  //ɾ��ĳ��Ԫ��

int Destory_List(pListNode L);  //����ѭ��˫����

int Empty_List(pListNode L);

int Length_List(pListNode L);
