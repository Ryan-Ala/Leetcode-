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
			cout << "�����ʽ��������������:" << endl;
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
			cout << "�����˳�!" << endl;
			break;
		default:
			cout << "δ�ҵ���Ӧ���������������: " << endl;
		}
	} while (num);
	return 0;
}