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
EM_Stat Employee_Des(PEmployee self);

#define OOC_Employee_Print(self) Employee_Print(self)
#define OOC_Employee_GetSalary(self) (((PEmployee)(self))->__salary)
#define OOC_Employee_GetName(self) (((PEmployee)(self))->__szName)
#define OOC_Employee_Des(self) Employee_Des(self)
#endif
