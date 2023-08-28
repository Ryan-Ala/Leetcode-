#include "Stu_one.h"
#include "Stu_two.h"
#include <map>
#include <fstream>
using namespace std;
map<int, Stu> Stu_map;

void Reload();//���ص�ǰ���м�¼
void SaveRecord();//���浱ǰ���м�¼
void Add_Stu();//���ѧ��ģ��
void Delete_Stu();//ɾ��ѧ��ģ��
void Traverse_Stu();//��������ѧ��

int main()
{
    int chioce = 0;
    while (1) {
        cout << "--------------------------------ѧ������ϵͳ----------------------------------------" << endl;
        cout << "1.���ѧ��" << endl;
        cout << "2.ɾ��ѧ��" << endl;
        cout << "3.���꼶���ѧ����Ϣ" << endl;
        cout << "4.���Ա����ѧ����Ϣ" << endl;
        cout << "5.����������ѧ��" << endl;
        cout << "6.���ѧ���ĳɼ����" << endl;
        cout << "7.��ʾȫ��ѧ��" << endl;
        cout << "8.���浱ǰ��¼" << endl;
        cout << "9.���ļ��ж�ȡ����" << endl;
        cout << "���������ѡ��:" << endl;
        cin >> chioce;
        switch (chioce) {
        case 1:
            Add_Stu();
            break;
        case 2:
            Delete_Stu();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            Traverse_Stu();
        case 8:
            SaveRecord();
            break;
        case 9:
            Reload();
        }

    }
    return 0;
}
//���ؼ�¼
void Reload() {
    ifstream savefile("save.txt", ios::in | ios::binary);
    string name;
    Stu stu;
    int b = 0;
    while (savefile.eof() != 1) {
        savefile.read((char*)&stu, sizeof(Stu));
        Stu_map.insert(map<int, Stu>::value_type(stu.Get_Id(), stu));
    }

    savefile.close();
}
//�����¼
void SaveRecord() {
    ofstream savefile("save.txt", ios::out | ios::binary);
    map<int, Stu>::iterator iter;
    iter = Stu_map.begin();
    string name;
    while (iter != Stu_map.end()) {
        Stu stu = (Stu)iter->second;
        savefile.write((char*)&(stu), sizeof(Stu));
        iter++;
    }
    savefile.close();
}
//����
void Traverse_Stu() {
    map<int, Stu>::iterator iter;
    iter = Stu_map.begin();
    while (iter != Stu_map.end()) {
        cout << iter->second << endl;
        iter++;
    }
}
//ɾ��
void Delete_Stu() {
    int id = 0;
    cout << "��������ɾ��ѧ����ѧ�ţ�" << endl;
    cin >> id;
    if (id != 0) {
        Stu_map.erase(id);
    }
}
//���
void Add_Stu() {//���ѧ��ģ��

    int chioce = 0;
    cout << "1.���1�꼶ѧ��" << endl;
    cout << "2.���2�꼶ѧ��" << endl;
    cout << "3.���������ѡ��: " << endl;
    cin >> chioce;
    switch (chioce) {
    case 1:
    {
        Stu_one stu;
        cin >> stu;
        Stu_map.insert(map<int, Stu>::value_type(stu.Get_Id(), stu));

    }
    break;
    case 2:
    {
        Stu_two stu;
        cin >> stu;
        Stu_map.insert(map<int, Stu>::value_type(stu.Get_Id(), stu));
    }
    break;
    }

}

