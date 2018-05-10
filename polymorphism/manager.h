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
EM_Stat Manager_Des(PManager self);

#define OOC_Manager_Print(self) OOC_VCALL(&(self)->super, Employee, Print)
#define OOC_Manager_GetLevel(self) OOC_VCALL(self, Manager, GetLevel)
#define OOC_Manager_GetSalary(self) OOC_VCALL(&(self)->super, Employee, GetSalary)
#define OOC_Manager_Des(self) OOC_VCALL(&(self)->super.super, Object, Des)

#endif

