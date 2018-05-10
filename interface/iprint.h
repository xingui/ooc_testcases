// iprint.h
#ifndef __IPRINT_h__
#define __IPRINT_h__

typedef struct IPrint * PIPrint;
struct IPrint
{
    void (*Print)(PObject);
    int __offset;
};

#define OOC_IPrint_Print(self) OOC_ICALL((self), Print) OOC_END_ICALL
#endif
