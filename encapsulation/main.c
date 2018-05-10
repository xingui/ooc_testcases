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
        salary = Employee_GetSalary(&em);
        Employee_Print(&em);
    }
    Employee_Des(&em);

    return 0;
}
