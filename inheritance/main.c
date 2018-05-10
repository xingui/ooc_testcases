// main.c

#include <stdio.h>
#include "util.h"
#include "employee.h"
#include "manager.h"

int main()
{
    Manager ma;

    if(Manager_Con(&ma, "Bob", 10000.0, 7))
    {
        float salary;
        salary = OOC_Employee_GetSalary(&ma);
        printf("Inheritance test: Salary--%f\n", salary);
        OOC_Manager_Print(&ma);
        OOC_Employee_Print(&ma);
    }
    OOC_Manager_Des(&ma);

    return 0;
}
