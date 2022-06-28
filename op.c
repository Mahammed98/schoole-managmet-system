#include "op.h"
extern uint_16 Size;
void MAIN_MENU()
{
    printf("\nPlease select the process: \n");
    printf("1: Create new student account \t 2: Delete student \n");
    printf("3: Show students list \t\t 4: Edit the student account\n");
    printf("5: Show students scores  \t 6: Updating score \n");
    printf("7: Exit from program\n\n");
    printf("******************************************\n");
    printf("Enter the operation number: ");
}
void op_(operation x, students *s1)
{
    switch (x)
    {
        case NEW_STUDENT:
            printf("*************Add new student ************\n");
            New_Student(s1);
            break;
        case DELETE_STUDENT:
            printf("************Delete the student************ \n");
            Delet_Student(s1);
            break;
        case STUDENT_LIST:
            Student_list(s1, s1->Size);
            break;
        case STUDENT_EDIT:
            printf("************Edit the student address ************ \n");
            Student_edit(s1);
            break;
        case RANK_STUDENT:
            Rank_student(s1, s1->Size);
            break;
        case STUDENT_SCORE:
            printf("************Edit the students score************ \n");
            Student_score(s1);
            break;
        case exit_:
            exit(0);
            break;
        default:
            printf("wrong number \n");
            break;
    }
}

