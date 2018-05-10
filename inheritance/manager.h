// manager.h
#ifndef __MANAGER_H__
#define __MANAGER_h__

typedef struct Manager
{
    Employee super;
    int __level;
} Manager;
typedef Manager* PManager;

EM_Stat Manager_Con(PManager self, const char *szName, float salary, int level);
void Manager_Print(PManager self);
EM_Stat Manager_Des(PManager self);

#define Manager_GetSalary(self) Employee_GetSalary(&(self)->super)
#endif
