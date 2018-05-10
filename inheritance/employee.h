// employee.h
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

typedef struct Employee
{
    const char *__szName;
    float __salary;
} Employee;
typedef Employee* PEmployee;

EM_Stat Employee_Con(PEmployee self, const char *szName, float salary);
void Employee_Print(PEmployee self);
float Employee_GetSalary(PEmployee self);
EM_Stat Employee_Des(PEmployee self);

#endif
