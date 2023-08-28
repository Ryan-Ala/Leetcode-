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
    // ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
    time_t now = time(NULL);
    // �� now ת��Ϊ tm �ṹ
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
    cout << "������ѧ�ţ�(10λ��" << endl;
    is.getline(temp, 50, '\n');
    stu.Set_id(atoi(temp));

    cout << "������������" << endl;
    is.getline(temp, 20, '\n');
    stu.Set_name(temp);

    cout << "�������Ա�(��/Ů)��" << endl;
    is.getline(temp, 10);
    if (!strcmp(temp, "��") || !strcmp(temp, "Ů")) {
        //true
    }
    else {
        cout << "�����Ա���ȷ��" << endl;
    }
    stu.Set_sex(temp);

    cout << "���������ʱ�䣺" << endl;
    cout << "�����������ݣ�" << endl;
    is.getline(temp, 10, '\n');
    time.year = atoi(temp);
    cout << "����������·ݣ�" << endl;
    is.getline(temp, 10);
    time.month = atoi(temp);
    cout << "������������ڣ�" << endl;
    is.getline(temp, 10, '\n');
    time.day = atoi(temp);
    stu.Set_BirthTime(time);

    cout << "��Ŀ�ɼ���" << endl;
    cout << "�������ĳɼ���" << endl;
    is.getline(temp, 10, '\n');
    grade.Chinese_grade = atof(temp);
    cout << "������ѧ�ɼ���" << endl;
    is.getline(temp, 10, '\n');
    grade.math_grade = atof(temp);
    cout << "����Ӣ��ɼ���" << endl;
    is.getline(temp, 10, '\n');
    grade.Enlish_grade = atof(temp);

    stu.Set_Grade(grade);
    return is;
}

ostream& operator<<(ostream& os, Stu& stu)
{

    os << "ѧ��-������Ϣ��" << endl;
    os << "--------------------" << endl;
    os << "ѧ�ţ�" << stu.Get_Id() << endl;
    os << "������" << stu.Get_name() << endl;
    os << "�Ա�" << stu.Get_sex() << endl;
    os << "���䣺" << stu.Caculate_Age() << endl;
    os << "�꼶:" << stu.Get_Type() << endl;
    os << "--------------------" << endl;
    os << "ѧ��-�ɼ���" << endl;
    os << "���ģ�" << stu.Get_Grade().Chinese_grade << endl;
    os << "��ѧ��" << stu.Get_Grade().math_grade << endl;
    os << "Ӣ�" << stu.Get_Grade().Enlish_grade << endl;
    os << "--------------------" << endl;
    return os;
}