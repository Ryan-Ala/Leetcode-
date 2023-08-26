#include"ListNode.h"
#include"Heap.h"
#include"contact.h"

 pListNode Init_contact()
{
	pListNode Head = Init_List();
	return Head;
}

 void menu()
 {
	 cout << endl;
	 cout << "*******************************" << endl;
	 cout << "***** 1.��� **** 2.ɾ�� ******" << endl;
	 cout << "***** 3.���� **** 4.�޸� ******" << endl;
	 cout << "***** 5.��ʾ **** 6.��� ******" << endl;
	 cout << "***** 7.���� **** 8.���� ******" << endl;
	 cout << "***** 0.�˳�(����) ************" << endl;
	 cout << "*******************************" << endl;
 }

 void menu_revise()
 {
	 cout << endl;
	 cout << "*******************************" << endl;
	 cout << "***** 1.���� **** 2.�Ա� ******" << endl;
	 cout << "***** 3.���� **** 4.�绰 ******" << endl;
	 cout << "***** 5.��ַ **** 6.��ϵ ******" << endl;
	 cout << "***** 0.�˳�(����) ************" << endl;
	 cout << "*******************************" << endl;
 }

 void menu_select()
 {
	 cout << endl;
	 cout << "*******************************" << endl;
	 cout << "***** 1.�����޸ĵ�ǰ��ϵ�� ****" << endl;
	 cout << "***** 2.�޸�������ϵ�� ********" << endl;
	 cout << "***** 0.�˳�(����) ************" << endl;
	 cout << "*******************************" << endl;
 }

 void menu_serch()
 {
	 cout << endl;
	 cout << "*******************************" << endl;
	 cout << "***** 1.���������� ************" << endl;
	 cout << "***** 2.���绰������� ********" << endl;
	 cout << "*******************************" << endl;
 }

 void scanf_peoinform(Datatype* x)
 {
	 if (!x)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 cout << endl << "��������ϵ����Ϣ:" << endl;
	 cout << endl << "����:" << endl;
	 cin >> x->name;
	 cout << endl << "�Ա�:" << endl;
	 cin >> x->sex;
	 cout << endl << "����:" << endl;
	 cin >> x->age;
	 cout << endl << "�绰:" << endl;
	 cin >> x->tele;
	 cout << endl << "��ַ:" << endl;
	 cin >> x->address;
	 cout << endl << "��ϵ:" << endl;
	 cin >> x->realation;
 }

 void printf_peoinform(Datatype* x)
 {
	 if (!x)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 cout << endl << "����: " << x->name << "\t\t"
		 << "�Ա�: " << x->sex << "\t\t"
		 << "����; " << x->age << "\t\t"
		 << "�绰; " << x->tele << "\t\t"
		 << "��ַ: " << x->address << "\t\t"
		 << "��ϵ: " << x->realation << endl;
 }

 void display_contact(contact* con)
 {
	 if (!con)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 if (con->next == con)
	 {
		 cout << "ͨѶ¼������ϵ��!" << endl;
		 return;
	 }
	 pListNode p = con->next;
	 while (p && p != con)
	 {
		 printf_peoinform(&(p->data));
		 p = p->next;
	 }
	 cout << endl;
 }

 void add_contact(contact* con)
 {
	 if (!con)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 Insert_End(con);
 }

 void delete_contact(contact* con)
 {
	 if (!con)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 cout << endl << "��������Ҫɾ������ϵ�˵�����:";
	 char name[MAX_NAME];
	 cin >> name;
	 pListNode pos = Find_List(con, name);
	 if (pos)
	 {     
		 Delete(pos);
		 cout << "ɾ���ɹ�!" << endl;
	 }
	 else 
		 cout << "δ�ҵ���Ϊ:" << name << "����ϵ�ˣ�ɾ��ʧ��!" << endl;
 }

 void serch_contact(contact* con)
 {
	 menu_serch();
	 LABEL:
	 int num = 0;
	 char size[MAX_SCANF] = { 0 };
	 cout << "Please Input a number: " << endl;
	 cin >> size;
	 while (strlen(size) > 1)
	 {
	 loop:
		 cout << "�����ʽ��������������:" << endl;
		 cin.ignore(1024, '\n');
		 cin >> size;
	 }
	 if (!isdigit(size[0]))
		 goto loop;
	 num = size[0] - '0';
	 if (num == 1)
		 serch_contact_name(con);
	 else if (num == 2)
		 serch_contact_tele(con);
	 else
	 {
		 cout << "δ�ҵ���Ӧ���������������! " << endl;
		 goto LABEL;
	 }
 }

 void serch_contact_name(contact* con)
 {
	 if (!con)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 cout << "��������Ҫ��ѯ����ϵ��: ";
	 char name[MAX_NAME];
	 cin >> name;
	 pListNode pos = Find_List(con, name);
	 if (pos)
	 {
		 printf_peoinform(&(pos->data));
		 cout << endl << "��������Լ���!" << endl;
		 _getch();
	 }
	 else
	 {
		 cout << "δ�ҵ���Ϊ:" << name << "����ϵ��!" << endl;
	 }
 }

 void serch_contact_tele(contact* con)
 {
	 if (!con)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 cout << "��������Ҫ��ѯ��ϵ�˵ĵ绰����: ";
	 char tele[MAX_TELE];
	 cin >> tele;
	 pListNode s = con->next;
	 while (s != con)
	 {
		 if (strstr(s->data.tele, tele))
		 {
			 printf_peoinform(&(s->data));
			 cout << endl << "��������Լ���!" << endl;
			 _getch();
			 return;
		 }
		 s = s->next;
	 }
	 if (s = con)
	 {
		 cout << "δ�ҵ���ϵ�绰����: " << tele << " ����ϵ��!" << endl;
	 }
 }

 void revise_contact(contact* con)
 {
	 if (!con)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 pListNode pos = NULL;
	 char name[MAX_NAME];
	 int num = 0;
	 int flag = 0;
	 char size[MAX_SCANF] = { 0 };
 LABEL1:
	 if (flag)
	 {
		 menu_select();
		 cout << "Please Input a number: " << endl;
		 cin >> size;
		 while (strlen(size) > 1)
		 {
		 loop:
			 cout << "�����ʽ��������������:" << endl;
			 cin.ignore(1024, '\n');
			 cin >> size;
		 }
		 if (!isdigit(size[0]))
			 goto loop;
		 num = size[0] - '0';
		 if (num == 1)
			 goto LABEL3;
		 else if (num == 2)
			 goto LABEL2;
		 else
		 {
			 cout << "�����˳�������ɹ�!" << endl;
			 return;
		 }
	 }
	 else
	 {
	 LABEL2:
		 cout << "��������Ҫ�޸ĵ���ϵ������: ";
	 }
	 cin >> name;
	 pos = Find_List(con, name);
	 if (pos)
	 {
		 cout << "��ѯ�ɹ�������ϵ����ϢΪ:" << endl;
		 printf_peoinform(&pos->data);
		 do
		 {
			 flag = 1;
		 LABEL3:
			 menu_revise();
			 cout << "��ѡ����Ҫ�޸ĵ���Ϣ:";
			 cin >> size;
			 while (strlen(size) > 1)
			 {
			 loop1:
				 cout << "�����ʽ��������������:" << endl;
				 cin.ignore(1024, '\n');
				 cin >> size;
			 }
			 if (!isdigit(size[0]))
				 goto loop1;
			 num = size[0] - '0';
			 switch (num)
			 {
			 case NAME:
				 cout << "��������������:" << endl;
				 cin >> pos->data.name;
				 cout << "�޸ĳɹ�!" << endl;
				 goto LABEL1;
				 break;
			 case SEX:
				 cout << "�����������Ա�:" << endl;
				 cin >> pos->data.sex;
				 cout << "�޸ĳɹ�!" << endl;
				 goto LABEL1;
				 break;
			 case AGE:
				 cout << "��������������:" << endl;
				 cin >> pos->data.age;
				 cout << "�޸ĳɹ�!" << endl;
				 goto LABEL1;
				 break;
			 case TELE:
				 cout << "����������绰:" << endl;
				 cin >> pos->data.tele;
				 cout << "�޸ĳɹ�!" << endl;
				 goto LABEL1;
				 break;
			 case ADRESS:
				 cout << "�����������ַ:" << endl;
				 cin >> pos->data.address;
				 cout << "�޸ĳɹ�!" << endl;
				 goto LABEL1;
				 break;
			 case REALATION:
				 cout << "�����������ϵ:" << endl;
				 cin >> pos->data.realation;
				 cout << "�޸ĳɹ�!" << endl;
				 goto LABEL1;
				 break;
			 case EXIT:
				 cout << "�����˳�������ɹ�!" << endl;
				 break;
			 default:
				 cout << "��Ч���������������: " << endl;
			 }
		 } while (num);
	 }
	 else
	 {
		 cout << "δ�ҵ���Ϊ: " << name << " ����ϵ�ˣ��޷��޸�!" << endl;
	 }
 }

 void Desstory_contact(contact*& con)
 {
	 if (!con)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 Destory_List(con);
	 con = Init_List();
	 cout << "��ճɹ�!" << endl;
 }

 int empty_contact(contact* con)
 {
	 if (!con)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 return Empty_List(con);
 }

 void sort_name(contact*& con)
 {
	 if (!con)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 int length = Length_List(con), i = 0;
	 peoinform** ret = (peoinform**)malloc(sizeof(peoinform*) * length);
	 contact* p = con->next;
	 while (p && p != con)
	 {
		 ret[i++] = &(p->data);
		 p = p->next;
	 }
	 pListNode a = Init_contact();
	 HeapSort(ret, length);
	 for (int i = 0; i < length; i++)
	 {
		 pListNode s = Buy_newNode(ret[i]);
		 Insert_End(a, s);
	 }
	 Destory_List(con);
	 con = a;
	 free(ret);
	 cout << "�ѽ�ͨѶ¼��ϵ�˰���������ĸ����!" << endl;
 }

  void Save_contact(contact* con)
 {
	  if (!con)
	  {
		  cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		  exit(1);
	  }
	 FILE* fin = fopen("contact.txt", "wb");
	 if (!fin)
	 {
		 cerr << "fopen_error!" << endl;
		 exit(1);
	 }
	 else
	 {
		 pListNode p = con->next;
		 while (p && p != con)
		 {
			 fwrite(&(p->data), sizeof(peoinform), 1, fin);
			 p = p->next;
		 }
		 fclose(fin);
		 fin = NULL;
		 cout << "����ɹ�!" << endl;
	 }
 }

  //�˳�ͨѶ¼���ͷ��ڴ�
  void Exit_contact(contact* con)
  {
	  if (!con)
	  {
		  cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		  exit(1);
	  }
	  Save_contact(con);
	  Destory_List(con);  //����ѭ��˫����
  }

 //�����ļ���Ϣ��ͨѶ¼
  void Loadcontact(contact* con)
  {
	  if (!con)
	  {
		  cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		  exit(1);
	  }
	  FILE* fin = fopen("contact.txt", "rb");
	  if (fin == NULL)
	  {
		  return;
	  }
	  else
	  {
		  peoinform temp = { 0 };
		  while (fread(&temp, sizeof(peoinform), 1, fin))
		  {
			  contact* newNode = Buy_newNode(&temp);
			  Insert_End(con, newNode);
		  }
	  }
	  fclose(fin);
  }