#include"contact.h"
using std::cout;
using std::endl;
using std::cin;
int main()
{
	int num = 0;
	contact con;
	Initcontact(&con);  //��ʼ��ͨѶ¼
	do
	{
		menu();
		cout << "Please Input a number: " << endl;
		cin >> num;
		switch (num)
		{
		case ADD:
			addcontact(&con);
			break;
		case DELETE:
			deletecontact(&con);
			break;
		case SERCH:
			serchcontact(&con);
			break;
		case REVISE:
			revisecontact(&con);
			break;
		case DISPALY:
			displaycontact(&con);
			break;
		case EMPTY:
			emptycontact(&con);
			break;
		case SORT:
			sortcontact(&con);
			break;
		case EXIT:
			Savecontact(&con);
			Exitcontact(&con);
			cout << "�����˳�!" << endl;
			break;
		default:
			cout << "δ�ҵ���Ӧ���������������: " << endl;
		}
	} while (num);
	return 0;
}