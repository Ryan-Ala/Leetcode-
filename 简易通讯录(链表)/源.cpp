#include"ListNode.h"

int main()
{
	int num = 0;
	char size[MAX_SCANF] = { 0 };
	contact* con = Init_contact();
	Loadcontact(con);
	do
	{
		menu();
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
		switch (num)
		{
		case ADD:
			add_contact(con);
			break;
		case DELETE:
			delete_contact(con);
			break;
		case SERCH:
			serch_contact(con);
			break;
		case REVISE:
			revise_contact(con);
			break;
		case DISPALY:
			display_contact(con);
			break;
		case EMPTY:
			Desstory_contact(con);
			break;
		case SORT:
			sort_name(con);
			break;
		case CLEAR_SCREEN:
			system("cls");
			break;
		case EXIT:
			Exit_contact(con);
			cout << "程序退出!" << endl;
			break;
		default:
			cout << "未找到对应的命令，请重新输入: " << endl;
		}
	} while (num);
	return 0;
}