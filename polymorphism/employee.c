// employee.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "ooc.h"
#include "employee.h"

const struct EmployeeClass __employee={
    {
        Employee_Des
    },
    Employee_Print,
    Employee_GetSalary
};

EM_Stat Employee_Con(PEmployee self, const char *szName, float salary)
{
    EM_Stat err = EM_OK;
    err = Object_Con(&self->super);
    if(EM_ERR == err)
        return err;
    ((PObject)self)->__vptr = (PObjectClass)&__employee;

    self->__szName = malloc(strlen(szName)+1);
    if(self->__szName == NULL)
        return EM_ERR;
    strcpy((char *)self->__szName, szName);
    self->__salary = salary;

    return EM_OK;
}

void Employee_Print(PEmployee self)
{
    printf("Name: %s\n\tSalary: %f\n", self->__szName, self->__salary);
}

float Employee_GetSalary(PEmployee self)
{
    return self->__salary;
}

EM_Stat Employee_Des(PEmployee self)
{
    free((void *)self->__szName);
    return EM_OK;
}
