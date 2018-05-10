// employee.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "util.h"
#include "ooc.h"
#include "icomparable.h"
#include "iprint.h"
#include "employee.h"

const struct EmployeeClass __employee={
    {
        Employee_Des
    },
    {
        Employee_Compare,
        offsetof(struct Employee, IComparable)
    },
    {
        Employee_Print,
        offsetof(struct Employee, IPrint)
    },
    Employee_GetSalary,
    Employee_GetName
};

EM_Stat Employee_Con(PEmployee self, const char *szName, float salary)
{
    EM_Stat err = EM_OK;
    err = Object_Con(&self->super);
    if(EM_ERR == err)
        return err;
    ((PObject)self)->__vptr = (PObjectClass)&__employee;
    self->IComparable = (struct IComparable *) &__employee.IComparable;
    self->IPrint = (struct IPrint *) &__employee.IPrint;

    self->__szName = malloc(strlen(szName)+1);
    if(self->__szName == NULL)
        return EM_ERR;
    strcpy((char *)self->__szName, szName);
    self->__salary = salary;

    return EM_OK;
}

int Employee_Compare(PEmployee self, PEmployee other)
{
    int res = 0;
    if(self->__salary > other->__salary)
        res = 1;
    else if(self->__salary < other->__salary)
        res = -1;

    return res;
}

void Employee_Print(PEmployee self)
{
    printf("Name: %s\n\tSalary: %f\n", self->__szName, self->__salary);
}

float Employee_GetSalary(PEmployee self)
{
    return self->__salary;
}

const char * Employee_GetName(PEmployee self)
{
    return self->__szName;
}

EM_Stat Employee_Des(PEmployee self)
{
    free((void *)self->__szName);
    return EM_OK;
}
