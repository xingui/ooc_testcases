// main.c

#include <stdio.h>
#include "util.h"
#include "ooc.h"
#include "icomparable.h"
#include "iprint.h"
#include "employee.h"
#include "manager.h"

int main()
{
    EM_Stat err;
    struct Employee em;
    struct Manager ma;
    PEmployee pEm[2];

    err = Employee_Con(&em, "Jim", 5000.0);
    err = Manager_Con(&ma, "Bob", 10000.0, 7);

    pEm[0] = &em;
    pEm[1] = &ma;
    {
        int i;
        for(i = 0; i < 2; i++)
        {
            OOC_Employee_Print(pEm[i]);
        }
    }
    int res = OOC_Employee_Compare(pEm[0], pEm[1]);
    printf("%s's salary(%f) is",
            OOC_Employee_GetName(pEm[0]),
            OOC_Employee_GetSalary(pEm[0]));
    if(res > 0)
    {
        printf(" higher than ");
    }
    else if(res < 0)
    {
        printf(" lower than ");
    }
    else
    {
        printf(" equal to ");
    }
    printf("%s(%f)\n",
        OOC_Employee_GetName(pEm[1]),
        OOC_Employee_GetSalary(pEm[1]));
    OOC_Manager_Des(&ma);
    OOC_Employee_Des(&em);

    return 0;
}
