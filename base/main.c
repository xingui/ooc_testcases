// main.c

#include <stdio.h>
#include "employee.h"

int main()
{
    struct Employee em={"Bob", 10000.0};

    PrintEmployee(&em);

    return 0;
}
