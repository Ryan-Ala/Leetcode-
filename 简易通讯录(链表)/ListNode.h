#pragma once

#include"contact.h"

typedef struct ListNode
{
	Datatype data;
	struct ListNode* next;
	struct ListNode* prev;   //指向下一个节点
} *pListNode, contact;

//初始化循环双链表
pListNode Init_List();

//创建一个新的节点
pListNode Buy_newNode(); 

pListNode Buy_newNode(peoinform* x); 

//L前插入
void Insert_List(pListNode L);  

//尾插
void Insert_End(pListNode L); 

void Insert_End(pListNode L, pListNode x); 

//头插
void Insert_Head(pListNode L);   

//删除
int Delete(pListNode s);  

//尾删
void Delete_End(pListNode L);   

//头删
void Delete_Head(pListNode L);  

//打印
void Printf_List(pListNode L);   

//任意位置插入
//int Insert_List(pListNode L, Datatype x, int i);   

//查找
pListNode Find_List(pListNode L, const char* x);   

//删除某个元素
int Delete_List(pListNode L, const char* x);  

//销毁
int Destory_List(pListNode L);  

//判空
int Empty_List(pListNode L);  

//长度
int Length_List(pListNode L);  

