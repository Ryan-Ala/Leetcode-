#pragma once
#include<iostream>
using std::cout;
using std::endl;
typedef int Datatype;

typedef struct ListNode
{
	Datatype data;
	struct ListNode* next;
	struct ListNode* prev;   //指向下一个节点
}ListNode, * pListNode;

ListNode* Init_List();

void Insert_End(ListNode* L, Datatype x); //尾插法

void Insert_Head(ListNode* L, Datatype x);   //头插法

void Printf_List(pListNode L);   //打印

pListNode Find_List(pListNode L, Datatype x);   //按值查找

int Insert_List(pListNode L, Datatype x, int i);   //任意位置插入

int Delete_(pListNode s);  //删除某一位置的元素

int Delete_List(pListNode L, Datatype x);  //删除某个元素

int Destory_List(pListNode L);  //销毁循环双链表

int Empty_List(pListNode L);

int Length_List(pListNode L);
