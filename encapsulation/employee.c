// employee.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "employee.h"

EM_Stat Employee_Con(PEmployee self, const char *szName, float salary)
{
    self->__szName = malloc(strlen(szName)+1);
    if(self->__szName == NULL)
        return EM_ERR;
    strcpy((char *)self->__szName, szName);
    self->__salary = salary;

    return EM_OK;
}

void Employee_Print(PEmployee self)
{
    printf("Name: %s, Salary: %f", self->__szName, self->__salary);
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
