// employee.c
#include <stdio.h>
#include "employee.h"

void PrintEmployee(struct Employee *pEm)
{
    printf("Name: %s, Salary: %f", pEm->szName, pEm->salary);
}
