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
	peoinform* nums;  //����Ϊָ������
	int sz;
	int capacity;
}contact;
//������ϵ��   
int Findcontactinform(const contact* pc, char* name);  //�ҵ��򷵻�1��δ���ҵ��򷵻�0
//��ʼ��ͨѶ¼
void Initcontact(contact* pc);
//��ʼ���˵�
void menu();
//��ӡ��ϵ��
void displaycontact(const contact* pc);
//�����ϵ��
void addcontact(contact* pc);
//ɾ����ϵ��
void deletecontact(contact* pc);
//��ѯ��ϵ��
void serchcontact(const contact* pc);
//�޸���ϵ��
void revisecontact(contact* pc);
//�����ϵ��
void emptycontact(contact* pc);
//����ͨѶ¼
void sortcontact(contact* pc);
//����������
int sort_name(const void* a, const void* b);
//�˳�ͨѶ¼���ͷ��ڴ�
void Exitcontact(contact* pc);