// manager.c

#include <stdio.h>
#include "util.h"
#include "ooc.h"
#include "employee.h"
#include "manager.h"

const struct ManagerClass __manager={
    {
        {
            Employee_Des
        },
        Manager_Print,
        Employee_GetSalary
    },
    Manager_GetLevel
};

EM_Stat Manager_Con(PManager self, const char *szName, float salary, int level)
{
    if(EM_ERR == Employee_Con(&self->super, szName, salary))
    {
        return EM_ERR;
    }
    ((PObject)self)->__vptr = (PObjectClass)&__manager;

    self->__level = level;

    return EM_OK;
}

void Manager_Print(PManager self)
{
    Employee_Print(&self->super);
    printf("\tLevel: %d\n", self->__level);
}

int Manager_GetLevel(PManager self)
{
    return self->__level;
}

