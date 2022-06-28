#ifndef OP_H_INCLUDED
#define OP_H_INCLUDED
#include "student.h"
typedef enum
{
    NEW_STUDENT= 1,DELETE_STUDENT, STUDENT_LIST, STUDENT_EDIT, RANK_STUDENT, STUDENT_SCORE, exit_

}operation;


void MAIN_MENU();
void op_(operation , students *);



#endif // OP_H_INCLUDED

