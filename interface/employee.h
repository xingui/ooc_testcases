// employee.h
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

typedef struct Employee* PEmployee;
typedef struct EmployeeClass * PEmployeeClass;

struct Employee
{
    struct Object super;
    PIComparable IComparable;
    PIPrint IPrint;
    const char *__szName;
    float __salary;
};

struct EmployeeClass
{
    struct ObjectClass super;
    struct IComparable IComparable;
    struct IPrint IPrint;
    float (*GetSalary)(PEmployee );
    const char *(*GetName)(PEmployee );
};


EM_Stat Employee_Con(PEmployee self, const char *szName, float salary);
int Employee_Compare(PEmployee self, PEmployee other);
void Employee_Print(PEmployee self);
float Employee_GetSalary(PEmployee self);
const char * Employee_GetName(PEmployee self);
EM_Stat Employee_Des(PEmployee self);

#define OOC_Employee_Print(self) OOC_ICALL(&(self)->IPrint, Print))
#define OOC_Employee_Compare(self, other) OOC_ICALL(&(self)->IComparable, Compare), (other))
#define OOC_Employee_GetSalary(self) OOC_VCALL(self, Employee, GetSalary)
#define OOC_Employee_GetName(self) OOC_VCALL(self, Employee, GetName)
#define OOC_Employee_Des(self) OOC_VCALL(&(self)->super, Object, Des)

#endif
