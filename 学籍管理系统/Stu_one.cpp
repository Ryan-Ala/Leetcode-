#include "Stu.h"
#include "Stu_one.h"
Stu_one::Stu_one(int stu_id, string name, string sex, BirthTime birthtime, Grade g) :Stu(stu_id, name, sex, birthtime, g) {
    Set_Type(1);

}

Stu_one::Stu_one() {
    Set_Type(1);
}
