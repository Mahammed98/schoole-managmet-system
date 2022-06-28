#include "op.h"
 int main()
{
    students s;
    operation op;

    initialized(&s);

    printf("**************************************************\n");
    printf("\t\tWelcome to SMS\n");
    printf("**************************************************\n");

    while (1)
    {
      MAIN_MENU();
      scanf("%hd",(uint_16 *)&op);
      op_(op, &s);
    }
    return 0;
}
