#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 15
#define MAX_ADRESS 20
#define MAX 1000
#define NUM 2
enum options { EXIT, ADD, DELETE, SERCH, REVISE, DISPALY, EMPTY, SORT };
typedef struct peoinform
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char address[MAX_ADRESS];
}peoinform;

typedef struct contact
{
	peoinform* nums;  //设置为指针类型
	int sz;
	int capacity;
}contact;
//查找联系人   
int Findcontactinform(const contact* pc, char* name);  //找到则返回1，未查找到则返回0
//初始化通讯录
void Initcontact(contact* pc);
//初始化菜单
void menu();
//打印联系人
void displaycontact(const contact* pc);
//添加联系人
void addcontact(contact* pc);
//删除联系人
void deletecontact(contact* pc);
//查询联系人
void serchcontact(const contact* pc);
//修改联系人
void revisecontact(contact* pc);
//清空联系人
void emptycontact(contact* pc);
//排序通讯录
void sortcontact(contact* pc);
//按名字排序
int sort_name(const void* a, const void* b);
//退出通讯录，释放内存
void Exitcontact(contact* pc);