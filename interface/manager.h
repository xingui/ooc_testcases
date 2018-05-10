// manager.h
#ifndef __MANAGER_H__
#define __MANAGER_h__

typedef struct Manager* PManager;
typedef struct ManagerClass* PManagerClass;

struct Manager
{
    struct Employee super;
    int __level;
};

struct ManagerClass
{
    struct EmployeeClass super;
    int (*GetLevel)(PManager );
};

EM_Stat Manager_Con(PManager self, const char *szName, float salary, int level);
void Manager_Print(PManager self);
int Manager_GetLevel(PManager self);
#define Manager_Des(self)               Employee_Des(&(self)->super)
#define Manager_Compare(self, other)    Employee_Compare(&(self)->super, other)
#define Manager_GetSalary(self)         Employee_GetSalary(&(self)->super)
#define Manager_GetName(self)           Employee_GetName(&(self)->super)


#define OOC_Manager_Print(self)             OOC_ICALL(&(self)->super.IPrint, Print))
#define OOC_Manager_Compare(self, other)    OOC_ICALL(&(self)->super.IComparable, Compare), (other))
#define OOC_Manager_GetLevel(self)          OOC_VCALL(self, Manager, GetLevel)
#define OOC_Manager_GetSalary(self)         OOC_VCALL(&(self)->super, Employee, GetSalary)
#define OOC_Manager_GetName(self)           OOC_VCALL(&(self)->super, Employee, GetName)
#define OOC_Manager_Des(self)               OOC_VCALL(&(self)->super.super, Object, Des)

#endif

