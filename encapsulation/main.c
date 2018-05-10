// main.c

#include <stdio.h>
#include "util.h"
#include "employee.h"

int main()
{
    Employee em;

    if(Employee_Con(&em, "Bob", 10000.0))
    {
        float salary;
        salary = OOC_Employee_GetSalary(&em);
        OOC_Employee_Print(&em);
    }
    OOC_Employee_Des(&em);

    return 0;
}
