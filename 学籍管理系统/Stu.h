#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <string>
#include <iostream>
#include <istream>
#include <stdlib.h>
#include <cstring>
#include <ctime>

using namespace std;
class BirthTime {
public:
    int year;
    int month;
    int day;

};
class Grade {
public:
    float math_grade;
    float Enlish_grade;
    float Chinese_grade;
};
class Stu
{
public:
    Stu(unsigned int Stu_id, string name, string sex, BirthTime birthtime, Grade g);
    Stu();
    unsigned int Get_Id();
    void Set_id(unsigned int id);
    string Get_name();
    void Set_name(string name);
    string Get_sex();
    void Set_sex(string sex);
    BirthTime Get_BirthTime();
    void Set_BirthTime(BirthTime b);
    int Get_Type();
    void Set_Type(int type);
    int Caculate_Age();
    void Set_Grade(Grade g);
    Grade Get_Grade();
    friend   istream& operator>>(istream& is, Stu& stu);
    friend   ostream& operator<<(ostream& os, Stu& stu);
private:
    long int stu_id;
    string name;
    string sex;
    BirthTime birthtime;
    Grade grade;
    int type;
};
