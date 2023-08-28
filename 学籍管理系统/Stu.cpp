#include "Stu.h"
Stu::Stu() {
}
void Stu::Set_Grade(Grade g) {
    this->grade = g;
}
Grade Stu::Get_Grade() {
    return this->grade;
}
Stu::Stu(unsigned int stu_id, string name, string sex, BirthTime birthtime, Grade g) {
    this->stu_id = stu_id;
    this->name = name;
    this->sex = sex;
    this->birthtime = birthtime;
    this->grade = g;

}
unsigned int Stu::Get_Id() {
    return this->stu_id;
}
void Stu::Set_id(unsigned int id) {
    this->stu_id = id;
}
string Stu::Get_name() {
    return this->name;
}
void Stu::Set_name(string name) {
    this->name = name;
}
string Stu::Get_sex() {
    return this->sex;
}
void Stu::Set_sex(string sex) {
    this->sex = sex;
}
BirthTime Stu::Get_BirthTime() {
    return this->birthtime;
}
void Stu::Set_BirthTime(BirthTime b) {
    this->birthtime = b;
}
int Stu::Get_Type() {
    return this->type;
}
void Stu::Set_Type(int type) {
    this->type = type;
}
int Stu::Caculate_Age() {
    // 基于当前系统的当前日期/时间
    time_t now = time(NULL);
    // 把 now 转换为 tm 结构
    tm* gmtm = gmtime(&now);
    int age = 0;
    int year_now = gmtm->tm_year + 1900;
    int birth_month = this->birthtime.month;
    if (gmtm->tm_mon >= birth_month && gmtm->tm_yday >= this->birthtime.day) {
        age = year_now - this->birthtime.year;
    }
    else {
        age = year_now - this->birthtime.year - 1;
    }
    return age;
}
istream& operator>>(istream& is, Stu& stu)
{
    char temp[50];
    is.getline(temp, 50, '\n');

    BirthTime time;
    Grade grade;
    cout << "请输入学号：(10位）" << endl;
    is.getline(temp, 50, '\n');
    stu.Set_id(atoi(temp));

    cout << "请输入姓名：" << endl;
    is.getline(temp, 20, '\n');
    stu.Set_name(temp);

    cout << "请输入性别(男/女)：" << endl;
    is.getline(temp, 10);
    if (!strcmp(temp, "男") || !strcmp(temp, "女")) {
        //true
    }
    else {
        cout << "输入性别不正确！" << endl;
    }
    stu.Set_sex(temp);

    cout << "请输入出生时间：" << endl;
    cout << "请输入出生年份：" << endl;
    is.getline(temp, 10, '\n');
    time.year = atoi(temp);
    cout << "请输入出生月份：" << endl;
    is.getline(temp, 10);
    time.month = atoi(temp);
    cout << "请输入出生日期：" << endl;
    is.getline(temp, 10, '\n');
    time.day = atoi(temp);
    stu.Set_BirthTime(time);

    cout << "科目成绩：" << endl;
    cout << "输入语文成绩：" << endl;
    is.getline(temp, 10, '\n');
    grade.Chinese_grade = atof(temp);
    cout << "输入数学成绩：" << endl;
    is.getline(temp, 10, '\n');
    grade.math_grade = atof(temp);
    cout << "输入英语成绩：" << endl;
    is.getline(temp, 10, '\n');
    grade.Enlish_grade = atof(temp);

    stu.Set_Grade(grade);
    return is;
}

ostream& operator<<(ostream& os, Stu& stu)
{

    os << "学生-基本信息：" << endl;
    os << "--------------------" << endl;
    os << "学号：" << stu.Get_Id() << endl;
    os << "姓名：" << stu.Get_name() << endl;
    os << "性别：" << stu.Get_sex() << endl;
    os << "年龄：" << stu.Caculate_Age() << endl;
    os << "年级:" << stu.Get_Type() << endl;
    os << "--------------------" << endl;
    os << "学生-成绩表" << endl;
    os << "语文：" << stu.Get_Grade().Chinese_grade << endl;
    os << "数学：" << stu.Get_Grade().math_grade << endl;
    os << "英语：" << stu.Get_Grade().Enlish_grade << endl;
    os << "--------------------" << endl;
    return os;
}