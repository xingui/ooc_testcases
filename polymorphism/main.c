// main.c

#include <stdio.h>
#include "util.h"
#include "ooc.h"
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
            OOC_Employee_Print(pEm[i]);
    }
    OOC_Manager_Des(&ma);
    OOC_Employee_Des(&em);

    return 0;
}
