// ooc.h
#ifndef __OOC_H__
#define __OOC_H__

typedef struct Object * PObject;
typedef struct ObjectClass *PObjectClass;

struct Object
{
    PObjectClass __vptr;
};

struct ObjectClass
{
    EM_Stat (*Des)(PObject);
};

EM_Stat Object_Con(PObject self);
EM_Stat Object_Des(PObject self);

#define OOC_VCALL(OX, CX, MX)\
    (*((P##CX##Class)(((PObject)(OX))->__vptr))->MX)(/*(P##CX)*/(OX))

#endif

