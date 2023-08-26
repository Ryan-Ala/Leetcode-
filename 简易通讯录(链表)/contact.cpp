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
	 cout << "***** 1.添加 **** 2.删除 ******" << endl;
	 cout << "***** 3.查找 **** 4.修改 ******" << endl;
	 cout << "***** 5.显示 **** 6.清空 ******" << endl;
	 cout << "***** 7.排序 **** 8.清屏 ******" << endl;
	 cout << "***** 0.退出(保存) ************" << endl;
	 cout << "*******************************" << endl;
 }

 void menu_revise()
 {
	 cout << endl;
	 cout << "*******************************" << endl;
	 cout << "***** 1.姓名 **** 2.性别 ******" << endl;
	 cout << "***** 3.年龄 **** 4.电话 ******" << endl;
	 cout << "***** 5.地址 **** 6.关系 ******" << endl;
	 cout << "***** 0.退出(保存) ************" << endl;
	 cout << "*******************************" << endl;
 }

 void menu_select()
 {
	 cout << endl;
	 cout << "*******************************" << endl;
	 cout << "***** 1.继续修改当前联系人 ****" << endl;
	 cout << "***** 2.修改其他联系人 ********" << endl;
	 cout << "***** 0.退出(保存) ************" << endl;
	 cout << "*******************************" << endl;
 }

 void menu_serch()
 {
	 cout << endl;
	 cout << "*******************************" << endl;
	 cout << "***** 1.按姓名查找 ************" << endl;
	 cout << "***** 2.按电话号码查找 ********" << endl;
	 cout << "*******************************" << endl;
 }

 void scanf_peoinform(Datatype* x)
 {
	 if (!x)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 cout << endl << "请输入联系人信息:" << endl;
	 cout << endl << "姓名:" << endl;
	 cin >> x->name;
	 cout << endl << "性别:" << endl;
	 cin >> x->sex;
	 cout << endl << "年龄:" << endl;
	 cin >> x->age;
	 cout << endl << "电话:" << endl;
	 cin >> x->tele;
	 cout << endl << "地址:" << endl;
	 cin >> x->address;
	 cout << endl << "关系:" << endl;
	 cin >> x->realation;
 }

 void printf_peoinform(Datatype* x)
 {
	 if (!x)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 cout << endl << "姓名: " << x->name << "\t\t"
		 << "性别: " << x->sex << "\t\t"
		 << "年龄; " << x->age << "\t\t"
		 << "电话; " << x->tele << "\t\t"
		 << "地址: " << x->address << "\t\t"
		 << "关系: " << x->realation << endl;
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
		 cout << "通讯录中无联系人!" << endl;
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
	 cout << endl << "请输入需要删除的联系人的姓名:";
	 char name[MAX_NAME];
	 cin >> name;
	 pListNode pos = Find_List(con, name);
	 if (pos)
	 {     
		 Delete(pos);
		 cout << "删除成功!" << endl;
	 }
	 else 
		 cout << "未找到名为:" << name << "的联系人，删除失败!" << endl;
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
		 cout << "输入格式错误！请重新输入:" << endl;
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
		 cout << "未找到对应的命令，请重新输入! " << endl;
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
	 cout << "请输入需要查询的联系人: ";
	 char name[MAX_NAME];
	 cin >> name;
	 pListNode pos = Find_List(con, name);
	 if (pos)
	 {
		 printf_peoinform(&(pos->data));
		 cout << endl << "按任意键以继续!" << endl;
		 _getch();
	 }
	 else
	 {
		 cout << "未找到名为:" << name << "的联系人!" << endl;
	 }
 }

 void serch_contact_tele(contact* con)
 {
	 if (!con)
	 {
		 cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		 exit(1);
	 }
	 cout << "请输入需要查询联系人的电话号码: ";
	 char tele[MAX_TELE];
	 cin >> tele;
	 pListNode s = con->next;
	 while (s != con)
	 {
		 if (strstr(s->data.tele, tele))
		 {
			 printf_peoinform(&(s->data));
			 cout << endl << "按任意键以继续!" << endl;
			 _getch();
			 return;
		 }
		 s = s->next;
	 }
	 if (s = con)
	 {
		 cout << "未找到联系电话包含: " << tele << " 的联系人!" << endl;
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
			 cout << "输入格式错误！请重新输入:" << endl;
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
			 cout << "程序退出，保存成功!" << endl;
			 return;
		 }
	 }
	 else
	 {
	 LABEL2:
		 cout << "请输入需要修改的联系人姓名: ";
	 }
	 cin >> name;
	 pos = Find_List(con, name);
	 if (pos)
	 {
		 cout << "查询成功！该联系人信息为:" << endl;
		 printf_peoinform(&pos->data);
		 do
		 {
			 flag = 1;
		 LABEL3:
			 menu_revise();
			 cout << "请选择需要修改的信息:";
			 cin >> size;
			 while (strlen(size) > 1)
			 {
			 loop1:
				 cout << "输入格式错误！请重新输入:" << endl;
				 cin.ignore(1024, '\n');
				 cin >> size;
			 }
			 if (!isdigit(size[0]))
				 goto loop1;
			 num = size[0] - '0';
			 switch (num)
			 {
			 case NAME:
				 cout << "请重新输入姓名:" << endl;
				 cin >> pos->data.name;
				 cout << "修改成功!" << endl;
				 goto LABEL1;
				 break;
			 case SEX:
				 cout << "请重新输入性别:" << endl;
				 cin >> pos->data.sex;
				 cout << "修改成功!" << endl;
				 goto LABEL1;
				 break;
			 case AGE:
				 cout << "请重新输入年龄:" << endl;
				 cin >> pos->data.age;
				 cout << "修改成功!" << endl;
				 goto LABEL1;
				 break;
			 case TELE:
				 cout << "请重新输入电话:" << endl;
				 cin >> pos->data.tele;
				 cout << "修改成功!" << endl;
				 goto LABEL1;
				 break;
			 case ADRESS:
				 cout << "请重新输入地址:" << endl;
				 cin >> pos->data.address;
				 cout << "修改成功!" << endl;
				 goto LABEL1;
				 break;
			 case REALATION:
				 cout << "请重新输入关系:" << endl;
				 cin >> pos->data.realation;
				 cout << "修改成功!" << endl;
				 goto LABEL1;
				 break;
			 case EXIT:
				 cout << "程序退出，保存成功!" << endl;
				 break;
			 default:
				 cout << "无效的命令，请重新输入: " << endl;
			 }
		 } while (num);
	 }
	 else
	 {
		 cout << "未找到名为: " << name << " 的联系人，无法修改!" << endl;
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
	 cout << "清空成功!" << endl;
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
	 cout << "已将通讯录联系人按姓名首字母排序!" << endl;
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
		 cout << "保存成功!" << endl;
	 }
 }

  //退出通讯录，释放内存
  void Exit_contact(contact* con)
  {
	  if (!con)
	  {
		  cerr << ":)  ERROR!    Function argument is nullptr!" << endl;
		  exit(1);
	  }
	  Save_contact(con);
	  Destory_List(con);  //销毁循环双链表
  }

 //加载文件信息至通讯录
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