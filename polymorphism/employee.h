// employee.h
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

typedef struct Employee* PEmployee;
typedef struct EmployeeClass * PEmployeeClass;

struct Employee
{
    struct Object super;
    const char *__szName;
    float __salary;
};

struct EmployeeClass
{
    struct ObjectClass super;
    void (*Print)(PEmployee );
    float (*GetSalary)(PEmployee );
};


EM_Stat Employee_Con(PEmployee self, const char *szName, float salary);
void Employee_Print(PEmployee self);
float Employee_GetSalary(PEmployee self);
EM_Stat Employee_Des(PEmployee self);

#define OOC_Employee_Print(self) OOC_VCALL(self, Employee, Print)
#define OOC_Employee_GetSalary(self) OOC_VCALL(self, Employee, GetSalary)
#define OOC_Employee_Des(self) OOC_VCALL(&(self)->super, Object, Des)

#endif
