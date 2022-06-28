#include "student.h"
#include "linear.h"
//static uint_8 flag ;
void initialized(students *ps)
{
        ps->rptr = NULL;
        ps->fptr = NULL;
        ps->Size = 0;
}// end function
///////////////////////////////////////////////////////////////////////////////
uint_16 empty_(students *ps)
{
    return ps->Size;
}
///////////////////////////////////////////////////////////////////
void Enter_data(node * pn)
{
      printf("enter the name: ");
      scanf("%s", pn->student.student_name);
      strlwr(pn->student.student_name);
      printf("enter the id: ");
      scanf("%ld", &pn->student.student_id);
      fflush(stdin); // to clear stdin buffer
      printf("enter the addres: ");
      scanf("%s", pn->student.student_addres);
      strlwr(pn->student.student_addres);
      printf("enter the score: ");
      scanf("%hd", &pn->student.student_score);
}// end enter data function

////////////////////////////////////////////////////////////////////////////////////////////

void New_Student(students * ps)
{

    node* pn = (node*)malloc(sizeof(node));


    if(!pn)
    {
        printf("Heap is full\n");
    }// end if
    else
    {

      Enter_data(pn); // enter data
      if(!ps->fptr)  // no node created
      {
          ps->fptr = pn;
          ps->rptr = pn;
          pn->pNext = NULL;
      }// end if
      else
      {
          ps->rptr->pNext = pn;
          ps->rptr = pn;     // move rear to next node
          pn->pNext = NULL;
      }// end second else

      ps->Size++;
    }// end first else
} // end new student function
//////////////////////////////////////////////////////////////////////////////////////////

void Delet_Student(students *ps)
{
    if(!empty_(ps))   // if no student added
    {
        printf("Data base is empty \n");
        return;
    } // end if

    uint_32 id_;
    node *temp2 = ps->fptr->pNext;
    node *temp1 = ps->fptr;

    printf("Enter the student ID: ");
    scanf("%ld",&id_);

    if(temp1->student.student_id == id_)  // if ID in first node
    {
        printf("Student which has ID (%ld) was deleted \n", id_);
        ps->fptr = temp1->pNext;
        free(temp1);
        ps->Size--;
    }// end if

    else if(!temp2)
    {
        printf("Wrong ID: \n");
    } // if enter wrong id

     else if(Linear_search(temp1, temp2, id_, ps->Size))
    {
        free(temp2);
        printf("Student which has ID (%ld) was deleted \n", id_);
        ps->Size--;
    }// end else if

    else
    {
        printf("WRONG ID \n");
    }// end else
    printf("size = %hd\n", ps->Size);
}// end delete function
//////////////////////////////////////////////////////////////////////////////////////////////

void Student_list(students * ps, uint_16 Size)
{
    if(!empty_(ps))   // if no student added
    {
        printf("Data base is empty \n");
        return;
    } // end if

    student_list temp;
    node * ptrs = ps->fptr;  // pointer for sorting
    node * pt = ps->fptr;   // pointer for printing

    /*
       bubble sort algorithm
    */

    for(uint_16 i = 0; i <= Size-2; i++)
        {
            for(uint_16 j = 0; j < Size-1; j++)
            {


               if(strcmp(ptrs->pNext->student.student_name, ptrs->student.student_name) < 0)
                  {
                      temp = ptrs->pNext->student;
                      ptrs->pNext->student = ptrs->student;
                      ptrs->student = temp;
                  }
                ptrs = ptrs->pNext;
            }
            ptrs = ps->fptr;  // reset ptrs equal to fptr
        }
    printf("*********************************************************\n");
    printf("Student \t ID \t address \t score  \n");
    printf("*********************************************************\n");

    do
    {
      printf("%s\t\t%ld\t%s\t\t%hd \n", pt->student.student_name, pt->student.student_id, pt->student.student_addres, pt->student.student_score);
      pt = pt->pNext;
    }while(pt);
}// end student list funtion

/////////////////////////////////////////////////////////////////////////////////////

void Student_edit(students *ps)
{
    if(!empty_(ps))   // if no student added
    {
        printf("Data base is empty \n");
        return;
    } // end if

    uint_32 id;
    node *temp1 = ps->fptr;
    printf("Enter the student ID: ");
    scanf("%ld",&id);


    if(search_id(temp1, id))
    {
        printf("edit address of the student :    ");
        scanf("%s", temp1->student.student_addres);
    }// end else if
    else
    {
        printf("WRONG ID \n");
    }// end else
}
//////////////////////////////////////////////////////////////////////////////////////
void Student_score(students *ps)
{
    if(!empty_(ps))   // if no student added
    {
        printf("Data base is empty \n");
        return;
    } // end if

    node * temp1 = ps->fptr;
    do
    {
        printf("Edit the student score :  ");
        scanf("%hd", &temp1->student.student_score);
        temp1 = temp1->pNext;
        printf("\n");
    }while(temp1);
}
void Rank_student(students * ps, uint_16 Size)
{
    if(!empty_(ps))   // if no student added
    {
        printf("Data base is empty \n");
        return;
    } // end if

    student_list temp;
    node * ptrs = ps->fptr;
    node * pt = ps->fptr;
    uint_16 rank_ = 1;

    for(uint_16 i = 0; i <= Size-2; i++)
        {
            for(uint_16 j = 0; j < Size-1; j++)
            {
               if(ptrs->student.student_score < ptrs->pNext->student.student_score)
                  {
                      temp = ptrs->pNext->student;
                      ptrs->pNext->student = ptrs->student;
                      ptrs->student = temp;
                  }
                ptrs = ptrs->pNext;
            }
            ptrs = ps->fptr;  // reset ptrs equal to fptr
        }
    printf("*********************************************************\n");
    printf("Rank    \t Student  \tscore  \n");
    printf("*********************************************************\n");

    do
    {
      printf("%d \t\t %s \t\t%hd \n",rank_,  pt->student.student_name, pt->student.student_score);
      pt = pt->pNext;
      rank_++;
    }while(pt); // end loop
} // end function

