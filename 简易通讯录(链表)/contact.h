#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<conio.h>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 20
#define MAX_ADRESS 40
#define MAX_REALATION 20
#define MAX_SCANF 100

typedef struct ListNode contact, * pListNode;

typedef struct peoinform
{
	char name[MAX_NAME];      //����
	char sex[MAX_SEX];        //�Ա�
	int age;                  //����
	char tele[MAX_TELE];      //�绰
	char address[MAX_ADRESS]; //��ַ
	char realation[MAX_REALATION];   //��ϵ
}peoinform, Datatype;

enum options { EXIT, ADD, DELETE, SERCH, REVISE, DISPALY, EMPTY, SORT, CLEAR_SCREEN };
enum options1 { NAME = 1, SEX, AGE, TELE, ADRESS, REALATION };
enum options2 { CONTINUE = 1 };

pListNode Init_contact();

//�˵�1
void menu();

//�˵�2
void menu_revise();

//�˵�3
void menu_select();

//�˵�4
void menu_serch();

//������ϵ����Ϣ
void scanf_peoinform(Datatype* x);   

//�����ϵ����Ϣ
void printf_peoinform(Datatype* x);

//���ͨѶ¼
void display_contact(contact* pc);

//�����ϵ��
void add_contact(contact* con);

//ɾ����ϵ��
void delete_contact(contact* con);

//��ѯ��ϵ��
void serch_contact(contact* con);


void serch_contact_name( contact* con);


void serch_contact_tele( contact* con);

//�޸���ϵ��
void revise_contact(contact* con);

//�����ϵ��
void Desstory_contact(contact*& con);

//�п�
int empty_contact(contact* con);

//��������
void sort_name(contact*& pc);

//����������
//int sort_name(const void* a, const void* b);

//�˳�
void Exit_contact(contact* pc);

//����
void Save_contact(contact* con);

//����
void Loadcontact(contact* pc);
