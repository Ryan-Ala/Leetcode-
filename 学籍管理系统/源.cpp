#include "Stu_one.h"
#include "Stu_two.h"
#include <map>
#include <fstream>
using namespace std;
map<int, Stu> Stu_map;

void Reload();//加载当前所有记录
void SaveRecord();//保存当前所有记录
void Add_Stu();//添加学生模块
void Delete_Stu();//删除学生模块
void Traverse_Stu();//遍历所有学生

int main()
{
    int chioce = 0;
    while (1) {
        cout << "--------------------------------学生管理系统----------------------------------------" << endl;
        cout << "1.添加学生" << endl;
        cout << "2.删除学生" << endl;
        cout << "3.按年级输出学生信息" << endl;
        cout << "4.按性别输出学生信息" << endl;
        cout << "5.按姓名检索学生" << endl;
        cout << "6.输出学生的成绩情况" << endl;
        cout << "7.显示全部学生" << endl;
        cout << "8.保存当前记录" << endl;
        cout << "9.从文件中读取数据" << endl;
        cout << "请输入你的选择:" << endl;
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
//加载记录
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
//保存记录
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
//遍历
void Traverse_Stu() {
    map<int, Stu>::iterator iter;
    iter = Stu_map.begin();
    while (iter != Stu_map.end()) {
        cout << iter->second << endl;
        iter++;
    }
}
//删除
void Delete_Stu() {
    int id = 0;
    cout << "请输入欲删除学生的学号：" << endl;
    cin >> id;
    if (id != 0) {
        Stu_map.erase(id);
    }
}
//添加
void Add_Stu() {//添加学生模块

    int chioce = 0;
    cout << "1.添加1年级学生" << endl;
    cout << "2.添加2年级学生" << endl;
    cout << "3.请输入你的选择: " << endl;
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

