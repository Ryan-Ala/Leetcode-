#include"contact.h"

void Loadcontact(contact* pc);

static int Findcontactinform(const contact* pc, char* name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (!strcmp(pc->nums[i].name, name))  //strcmp若一样则返回0，不一样返回非0
		{
			return i + 1;
		}
	}  //添加 !
	return 0;
}

//初始化通讯录
void Initcontact(contact* pc)
{
	pc->sz = 0;
	pc->capacity = NUM;  //将容量设置为3
	pc->nums = (peoinform*)calloc(NUM, sizeof(peoinform));//初始化动态开辟内存
	if (pc->nums == NULL)
	{
		cout << "初始化通讯录遇到异常! " << strerror(errno) << endl;//errno 包含头文件<errno.h>
		return;
	}
	//加载信息至通讯录
	Loadcontact(pc);
}

//初始化菜单
void menu()
{
	cout << "*******************************" << endl;
	cout << "***** 1.添加 **** 2.删除 ******" << endl;
	cout << "***** 3.查找 **** 4.修改 ******" << endl;
	cout << "***** 5.显示 **** 6.清空 ******" << endl;
	cout << "***** 7.排序 **** 0.退出 ******" << endl;
	cout << "*******************************" << endl;
}

void displaycontact(const contact* pc)
{
	if (pc->sz == 0)
	{
		cout << "通讯录中无联系人，打印失败" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < pc->sz; i++)
		{
			cout << "姓名: " << pc->nums[i].name << "\t"
				<< "性别: " << pc->nums[i].sex << "\t"
				<< "年龄; " << pc->nums[i].age << "\t"
				<< "电话; " << pc->nums[i].tele << "\t"
				<< "地址: " << pc->nums[i].address << endl;
		}
		cout << "打印完毕" << endl;
	}
	return;
}

void addcontact(contact* pc)
{
	if (pc->sz >= pc->capacity)
	{
		peoinform* ptr = (peoinform*)realloc(pc->nums, sizeof(peoinform) * (pc->capacity + NUM));
		if (ptr == NULL)
		{
			cout << "通讯录扩容失败! " << strerror(errno) << endl;
			return;
		}
		pc->nums = ptr;
		pc->capacity += NUM;
	}
	cout << "请输入联系人的姓名: ";
	cin >> pc->nums[pc->sz].name;
	cout << endl << "请输入联系人的性别: ";
	cin >> pc->nums[pc->sz].sex;
	cout << endl << "请输入联系人的年龄: ";
	cin >> pc->nums[pc->sz].age;
	cout << endl << "请输入联系人的电话: ";
	cin >> pc->nums[pc->sz].tele;
	cout << endl << "请输入联系人的地址: ";
	cin >> pc->nums[pc->sz].address;
	cout << "保存成功" << endl;
	pc->sz++;
}

void deletecontact(contact* pc)
{
	cout << "请输入需要删除的联系人的姓名:";
	char name[MAX_NAME];
	cin >> name;
	int pos = Findcontactinform(pc, name);  //pos记录当前该联系人数据在数组中的位置+1
	if (pos)
	{  //有该联系人
		for (int i = pos - 1; i < pc->sz - 1; i++)   //将数组整体向前移动
		{
			pc->nums[i] = pc->nums[i + 1];
		}
		pc->sz--;
	}
	else
	{   //无该联系人
		cout << "未找到该联系人，删除失败!" << endl;
	}
}

void serchcontact(const contact* pc)
{
	cout << "请输入需要查询的联系人: ";
	char name[MAX_NAME];
	cin >> name;
	int pos = Findcontactinform(pc, name);
	if (pos)
	{
		cout << "查找成功!" << endl;
		cout << "姓名: " << pc->nums[pos - 1].name << "\t"
			<< "性别: " << pc->nums[pos - 1].sex << "\t"
			<< "年龄; " << pc->nums[pos - 1].age << "\t"
			<< "电话; " << pc->nums[pos - 1].tele << "\t"
			<< "地址: " << pc->nums[pos - 1].address << endl;
	}
	else
	{
		cout << "查找失败!" << endl;
	}
}

void revisecontact(contact* pc)
{
	cout << "请输入需要修改的联系人姓名: ";
	char name[MAX_NAME];
	cin >> name;
	int pos = Findcontactinform(pc, name);
	if (pos)
	{
		cout << "已找到该联系人!" << endl;
		cout << "请重新输入联系人的姓名: ";
		cin >> pc->nums[pos - 1].name;
		cout << endl << "请重新输入联系人的性别: ";
		cin >> pc->nums[pos - 1].sex;
		cout << endl << "请重新输入联系人的年龄: ";
		cin >> pc->nums[pos - 1].age;
		cout << endl << "请重新输入联系人的电话: ";
		cin >> pc->nums[pos - 1].tele;
		cout << endl << "请重新输入联系人的地址: ";
		cin >> pc->nums[pos - 1].address;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "未找到目标联系人，无法修改!" << endl;
	}
}

void emptycontact(contact* pc)
{
	if (pc->sz == 0)
	{
		cout << "该联系人列表已经是空!" << endl;
	}
	else
	{
		Initcontact(pc); //重新初始化通讯录
	}
}

void sortcontact(contact* pc)
{
	if (pc->sz == 0)
		cout << "通讯录为空，无法排序!" << endl;
	else
	{
		qsort(pc->nums, pc->sz, sizeof(peoinform), sort_name);
		cout << "排序成功(按姓名)" << endl;
	}
}

int sort_name(const void* a, const void* b)  //按名字进行排序
{
	return strcmp(((peoinform*)a)->name, ((peoinform*)b)->name);
	// ((peoinform*)a),这里在强制类型转换后再加一层括号是为了让形参a被强制类型转换，因为->的结合性高，不加括号，a会与->name先结合，导致程序出错
}

//退出通讯录，释放内存
void Exitcontact(contact* pc)
{
	free(pc->nums);
	pc->nums = NULL;
	pc->sz = 0;
	pc->capacity = 0;
	cout << "释放内存成功!" << endl;
}

//保存至文本文件
void Savecontact(contact* pc)
{
	FILE* p = fopen("contact.txt", "wb");  //以二进制的方式写入 txt文件中去;
	if (p == NULL)
	{
		perror("Savecontact");  //若打开错误则抛出异常
		return;
	}
	else
	{
		for (int i = 0; i < pc->sz; i++)
		{
			fwrite(pc->nums + i, sizeof(peoinform), 1, p);
		}
		fclose(p);
		p = NULL;
		cout << "保存成功!" << endl;
	}
}

//加载文件信息至通讯录
void Loadcontact(contact* pc)
{
	FILE* p = fopen("contact.txt", "rb");
	if (p == NULL)
	{
		perror("Loadcontact");
		return;
	}
	else
	{
		peoinform temp = { 0 };
		while (fread(&temp, sizeof(peoinform), 1, p))
		{
			if (pc->sz >= pc->capacity)
			{
				peoinform* ptr = (peoinform*)realloc(pc->nums, sizeof(peoinform) * (pc->capacity + NUM));
				if (ptr == NULL)
				{
					cout << "通讯录扩容失败! " << strerror(errno) << endl;
					return;
				}
				pc->nums = ptr;  //确认动态开辟成功在将指针赋值
				pc->capacity += NUM;
				cout << "初始化扩容成功!" << endl;
			}
			pc->nums[pc->sz] = temp;
			pc->sz++;
		}
	}
	fclose(p);
	p = NULL;
}
