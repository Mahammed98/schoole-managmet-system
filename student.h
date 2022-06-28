#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "datatype.h"
typedef struct {
    uint_8 student_name [15];
    uint_32 student_id;
    uint_8 student_addres[10];
    uint_16 student_score;
}student_list;// student data

typedef struct mynode{
    student_list student;
    struct mynode * pNext;
}node;

typedef struct {
    node * fptr ;     // head
    node * rptr ;     // back
    uint_16 Size ;
}students;

//////////////////////////// function prototypes //////////////////////////////
uint_16 empty_(students *);                  // check list
void initialized(students *);                // used to initialized node
void New_Student(students *);                // add new student
void Delet_Student(students *);              // delete student with ID
void Enter_data(node *);                     // enter student data
void Student_list(students * , uint_16);     // show data of students
void Student_edit(students *);               // edit address of student
void Student_score(students *);              // edit score of all student
void Rank_student(students * , uint_16 );    // show score for students

#endif // STUDENT_H_INCLUDED

