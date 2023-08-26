#pragma once

#include"contact.h"

typedef struct ListNode
{
	Datatype data;
	struct ListNode* next;
	struct ListNode* prev;   //ָ����һ���ڵ�
} *pListNode, contact;

//��ʼ��ѭ��˫����
pListNode Init_List();

//����һ���µĽڵ�
pListNode Buy_newNode(); 

pListNode Buy_newNode(peoinform* x); 

//Lǰ����
void Insert_List(pListNode L);  

//β��
void Insert_End(pListNode L); 

void Insert_End(pListNode L, pListNode x); 

//ͷ��
void Insert_Head(pListNode L);   

//ɾ��
int Delete(pListNode s);  

//βɾ
void Delete_End(pListNode L);   

//ͷɾ
void Delete_Head(pListNode L);  

//��ӡ
void Printf_List(pListNode L);   

//����λ�ò���
//int Insert_List(pListNode L, Datatype x, int i);   

//����
pListNode Find_List(pListNode L, const char* x);   

//ɾ��ĳ��Ԫ��
int Delete_List(pListNode L, const char* x);  

//����
int Destory_List(pListNode L);  

//�п�
int Empty_List(pListNode L);  

//����
int Length_List(pListNode L);  

