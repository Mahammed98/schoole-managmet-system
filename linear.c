#include "linear.h"
bool Linear_search( node * pt1, node * pt2,  uint_32 key, uint_16 Size)
{
   do
    {
        /* pt1 pointed to previous
           node which will be deleted, and
           pt2 pointed to node
           wh
           ich will be deleted
        */

        if(pt2->student.student_id == key)
        {
            pt1->pNext = pt2->pNext;
            return 1;
        }
        else
        {
            if(Size == 2)             // if we have only two node
            {
                pt2->pNext = NULL;
                pt1 = pt1->pNext;
            }
            else
            {
                pt2 = pt2->pNext; // pointed to next node
                pt1 = pt1->pNext;
            }
        }// end main else

    }while(pt2->pNext);
      // end while
    return 0;

}
bool search_id(node *ptr1, uint_32 key)
{
do
    {
        if(ptr1->student.student_id == key)
        {
            return 1;
        }
        else
        {
            ptr1 = ptr1->pNext;
        }// end main else

    }while(ptr1->pNext);
      // end while
    return 0;
}
