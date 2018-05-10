// ooc.c
#include <stdio.h>
#include "util.h"
#include "ooc.h"

const struct ObjectClass __Object={
    Object_Des};

EM_Stat Object_Con(PObject self)
{
    self->__vptr = (PObjectClass)&__Object;
    return EM_OK;
}


EM_Stat Object_Des(PObject self)
{
    return EM_OK;
}

