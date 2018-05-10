// manager.c

#include <stdio.h>
#include "util.h"
#include "employee.h"
#include "manager.h"


EM_Stat Manager_Con(PManager self, const char *szName, float salary, int level)
{
    if(EM_ERR == Employee_Con(&self->super, szName, salary))
    {
        return EM_ERR;
    }
    self->__level = level;

    return EM_OK;
}

void Manager_Print(PManager self)
{
    Employee_Print(&self->super);
    printf(", Level: %d", self->__level);
}

