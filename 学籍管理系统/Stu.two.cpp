#include "Stu_two.h"
Stu_two::Stu_two(int stu_id, string name, string sex, BirthTime birthtime, Grade g) :Stu(stu_id, name, sex, birthtime, g) {
    Set_Type(2);
}
Stu_two::Stu_two() {
    Set_Type(2);
}