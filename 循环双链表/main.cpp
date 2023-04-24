#include"ListNode.h"
int main()
{
	pListNode con = Init_List();
	int a[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		Insert_End(con, a[i]);
	}
	Printf_List(con);
	cout << endl;
	Insert_List(con, 10, 3);
	Insert_List(con, -10, 6);
	Printf_List(con);
	cout << endl << Length_List(con) << endl;
	for (int i = 0; i < 5; i++)
	{
		Insert_Head(con, a[i]);
	}
	Printf_List(con);
	cout << endl;
	Delete_List(con, -10);
	Printf_List(con);
	cout << endl << Length_List(con) << endl;
	cout << Empty_List(con) << endl;
	Destory_List(con);
}