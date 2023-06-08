#include<iostream>
int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int n1 = 0, n0;
    while (studentsSize--)
    {
        if (students[studentsSize])
            n1++;
    }
    n0 = sandwichesSize - n1;
    for (int i = 0; i < sandwichesSize; i++)
    {
        if (sandwiches[i] == 1 && n1 > 0)
        {
            n1--;
        }
        else if (sandwiches[i] == 0 && n0 > 0)
        {
            n0--;
        }
        else
            break;
    }
    return n1 + n0;
}