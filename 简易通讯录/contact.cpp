#include"contact.h"

void Loadcontact(contact* pc);

static int Findcontactinform(const contact* pc, char* name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if (!strcmp(pc->nums[i].name, name))  //strcmp��һ���򷵻�0����һ�����ط�0
		{
			return i + 1;
		}
	}  //��� !
	return 0;
}

//��ʼ��ͨѶ¼
void Initcontact(contact* pc)
{
	pc->sz = 0;
	pc->capacity = NUM;  //����������Ϊ3
	pc->nums = (peoinform*)calloc(NUM, sizeof(peoinform));//��ʼ����̬�����ڴ�
	if (pc->nums == NULL)
	{
		cout << "��ʼ��ͨѶ¼�����쳣! " << strerror(errno) << endl;//errno ����ͷ�ļ�<errno.h>
		return;
	}
	//������Ϣ��ͨѶ¼
	Loadcontact(pc);
}

//��ʼ���˵�
void menu()
{
	cout << "*******************************" << endl;
	cout << "***** 1.��� **** 2.ɾ�� ******" << endl;
	cout << "***** 3.���� **** 4.�޸� ******" << endl;
	cout << "***** 5.��ʾ **** 6.��� ******" << endl;
	cout << "***** 7.���� **** 0.�˳� ******" << endl;
	cout << "*******************************" << endl;
}

void displaycontact(const contact* pc)
{
	if (pc->sz == 0)
	{
		cout << "ͨѶ¼������ϵ�ˣ���ӡʧ��" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < pc->sz; i++)
		{
			cout << "����: " << pc->nums[i].name << "\t"
				<< "�Ա�: " << pc->nums[i].sex << "\t"
				<< "����; " << pc->nums[i].age << "\t"
				<< "�绰; " << pc->nums[i].tele << "\t"
				<< "��ַ: " << pc->nums[i].address << endl;
		}
		cout << "��ӡ���" << endl;
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
			cout << "ͨѶ¼����ʧ��! " << strerror(errno) << endl;
			return;
		}
		pc->nums = ptr;
		pc->capacity += NUM;
	}
	cout << "��������ϵ�˵�����: ";
	cin >> pc->nums[pc->sz].name;
	cout << endl << "��������ϵ�˵��Ա�: ";
	cin >> pc->nums[pc->sz].sex;
	cout << endl << "��������ϵ�˵�����: ";
	cin >> pc->nums[pc->sz].age;
	cout << endl << "��������ϵ�˵ĵ绰: ";
	cin >> pc->nums[pc->sz].tele;
	cout << endl << "��������ϵ�˵ĵ�ַ: ";
	cin >> pc->nums[pc->sz].address;
	cout << "����ɹ�" << endl;
	pc->sz++;
}

void deletecontact(contact* pc)
{
	cout << "��������Ҫɾ������ϵ�˵�����:";
	char name[MAX_NAME];
	cin >> name;
	int pos = Findcontactinform(pc, name);  //pos��¼��ǰ����ϵ�������������е�λ��+1
	if (pos)
	{  //�и���ϵ��
		for (int i = pos - 1; i < pc->sz - 1; i++)   //������������ǰ�ƶ�
		{
			pc->nums[i] = pc->nums[i + 1];
		}
		pc->sz--;
	}
	else
	{   //�޸���ϵ��
		cout << "δ�ҵ�����ϵ�ˣ�ɾ��ʧ��!" << endl;
	}
}

void serchcontact(const contact* pc)
{
	cout << "��������Ҫ��ѯ����ϵ��: ";
	char name[MAX_NAME];
	cin >> name;
	int pos = Findcontactinform(pc, name);
	if (pos)
	{
		cout << "���ҳɹ�!" << endl;
		cout << "����: " << pc->nums[pos - 1].name << "\t"
			<< "�Ա�: " << pc->nums[pos - 1].sex << "\t"
			<< "����; " << pc->nums[pos - 1].age << "\t"
			<< "�绰; " << pc->nums[pos - 1].tele << "\t"
			<< "��ַ: " << pc->nums[pos - 1].address << endl;
	}
	else
	{
		cout << "����ʧ��!" << endl;
	}
}

void revisecontact(contact* pc)
{
	cout << "��������Ҫ�޸ĵ���ϵ������: ";
	char name[MAX_NAME];
	cin >> name;
	int pos = Findcontactinform(pc, name);
	if (pos)
	{
		cout << "���ҵ�����ϵ��!" << endl;
		cout << "������������ϵ�˵�����: ";
		cin >> pc->nums[pos - 1].name;
		cout << endl << "������������ϵ�˵��Ա�: ";
		cin >> pc->nums[pos - 1].sex;
		cout << endl << "������������ϵ�˵�����: ";
		cin >> pc->nums[pos - 1].age;
		cout << endl << "������������ϵ�˵ĵ绰: ";
		cin >> pc->nums[pos - 1].tele;
		cout << endl << "������������ϵ�˵ĵ�ַ: ";
		cin >> pc->nums[pos - 1].address;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "δ�ҵ�Ŀ����ϵ�ˣ��޷��޸�!" << endl;
	}
}

void emptycontact(contact* pc)
{
	if (pc->sz == 0)
	{
		cout << "����ϵ���б��Ѿ��ǿ�!" << endl;
	}
	else
	{
		Initcontact(pc); //���³�ʼ��ͨѶ¼
	}
}

void sortcontact(contact* pc)
{
	if (pc->sz == 0)
		cout << "ͨѶ¼Ϊ�գ��޷�����!" << endl;
	else
	{
		qsort(pc->nums, pc->sz, sizeof(peoinform), sort_name);
		cout << "����ɹ�(������)" << endl;
	}
}

int sort_name(const void* a, const void* b)  //�����ֽ�������
{
	return strcmp(((peoinform*)a)->name, ((peoinform*)b)->name);
	// ((peoinform*)a),������ǿ������ת�����ټ�һ��������Ϊ�����β�a��ǿ������ת������Ϊ->�Ľ���Ըߣ��������ţ�a����->name�Ƚ�ϣ����³������
}

//�˳�ͨѶ¼���ͷ��ڴ�
void Exitcontact(contact* pc)
{
	free(pc->nums);
	pc->nums = NULL;
	pc->sz = 0;
	pc->capacity = 0;
	cout << "�ͷ��ڴ�ɹ�!" << endl;
}

//�������ı��ļ�
void Savecontact(contact* pc)
{
	FILE* p = fopen("contact.txt", "wb");  //�Զ����Ƶķ�ʽд�� txt�ļ���ȥ;
	if (p == NULL)
	{
		perror("Savecontact");  //���򿪴������׳��쳣
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
		cout << "����ɹ�!" << endl;
	}
}

//�����ļ���Ϣ��ͨѶ¼
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
					cout << "ͨѶ¼����ʧ��! " << strerror(errno) << endl;
					return;
				}
				pc->nums = ptr;  //ȷ�϶�̬���ٳɹ��ڽ�ָ�븳ֵ
				pc->capacity += NUM;
				cout << "��ʼ�����ݳɹ�!" << endl;
			}
			pc->nums[pc->sz] = temp;
			pc->sz++;
		}
	}
	fclose(p);
	p = NULL;
}
