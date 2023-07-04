#include<iostream>
#include"stack.h"
using namespace std;


int main()
{
	T a;
	char ch;
	Stack st;
	cout << "Please enter 'A' to push stack!" << endl
		<< "'P' to pop from" << endl << "'Q'to quit!" << endl;
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get()!= '\n')
			char sh = ch;
		switch (ch)
		{
		case'a':
		case 'A':
			if (st.isfull())
				cout << "The stack if full!" << endl;
			else
			{
				cout << "Enter a number what you want psuh:" << endl;
				cin >> a;
				st.push(a);
				cout << "push success!" << endl;
			}
			break;
		case 'p':
		case'P':
			if (st.isempty())
				cout << "The stack is empty!" << endl;
			else
			{
				st.pop(a);
				cout << "pop success! " << a << " already poped!" << endl;
			}
			break;
		}
		cout << "Please enter 'A' to push stack!" << endl
			<< "'P' to pop from" << endl << "'Q'to quit!" << endl;
	}
}