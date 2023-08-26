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
	char name[MAX_NAME];      //姓名
	char sex[MAX_SEX];        //性别
	int age;                  //年龄
	char tele[MAX_TELE];      //电话
	char address[MAX_ADRESS]; //地址
	char realation[MAX_REALATION];   //关系
}peoinform, Datatype;

enum options { EXIT, ADD, DELETE, SERCH, REVISE, DISPALY, EMPTY, SORT, CLEAR_SCREEN };
enum options1 { NAME = 1, SEX, AGE, TELE, ADRESS, REALATION };
enum options2 { CONTINUE = 1 };

pListNode Init_contact();

//菜单1
void menu();

//菜单2
void menu_revise();

//菜单3
void menu_select();

//菜单4
void menu_serch();

//输入联系人信息
void scanf_peoinform(Datatype* x);   

//输出联系人信息
void printf_peoinform(Datatype* x);

//输出通讯录
void display_contact(contact* pc);

//添加联系人
void add_contact(contact* con);

//删除联系人
void delete_contact(contact* con);

//查询联系人
void serch_contact(contact* con);


void serch_contact_name( contact* con);


void serch_contact_tele( contact* con);

//修改联系人
void revise_contact(contact* con);

//清空联系人
void Desstory_contact(contact*& con);

//判空
int empty_contact(contact* con);

//名字排序
void sort_name(contact*& pc);

//按名字排序
//int sort_name(const void* a, const void* b);

//退出
void Exit_contact(contact* pc);

//保存
void Save_contact(contact* con);

//加载
void Loadcontact(contact* pc);
