// employee.h
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

struct Employee
{
    const char *szName;
    float salary;
};

void PrintEmployee(struct Employee *pEm);

#endif
