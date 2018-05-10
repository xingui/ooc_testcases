// manager.h
#ifndef __MANAGER_H__
#define __MANAGER_H__

typedef struct Manager
{
    Employee super;
    int __level;
} Manager;
typedef Manager* PManager;

EM_Stat Manager_Con(PManager self, const char *szName, float salary, int level);
void Manager_Print(PManager self);

#define OOC_Manager_Print(self) Manager_Print(self)
#define OOC_Manager_GetSalary(self) (((PManager)(self))->super.__salary)
#define OOC_Manager_GetName(self) (((PManager)(self))->super.__szName)
#define OOC_Manager_Des(self) Employee_Des(self)
#endif
