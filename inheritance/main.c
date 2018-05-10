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
        salary = Manager_GetSalary(&ma);
        printf("Inheritance test: Salary--%f\n", salary);
        Manager_Print(&ma);
    }
    Manager_Des(&ma);

    return 0;
}
