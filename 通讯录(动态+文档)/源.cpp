#include"contact.h"
using std::cout;
using std::endl;
using std::cin;
int main()
{
	int num = 0;
	contact con;
	Initcontact(&con);  //初始化通讯录
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
			cout << "程序退出!" << endl;
			break;
		default:
			cout << "未找到对应的命令，请重新输入: " << endl;
		}
	} while (num);
	return 0;
}