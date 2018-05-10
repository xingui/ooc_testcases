// manager.c

#include <stdio.h>
#include <stddef.h>
#include "util.h"
#include "ooc.h"
#include "icomparable.h"
#include "iprint.h"
#include "employee.h"
#include "manager.h"

const struct ManagerClass __manager={
    {
        {
            Employee_Des
        },
        {
            Employee_Compare,
            offsetof(struct Manager, super.IComparable)
        },
        {
            Manager_Print,
            offsetof(struct Manager, super.IPrint)
        },
        Employee_GetSalary,
        Employee_GetName
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
    self->super.IComparable = (PIComparable) &__manager.super.IComparable;
    self->super.IPrint = (PIPrint) &__manager.super.IPrint;

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

