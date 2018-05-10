// icomparable.h
#ifndef __ICOMPARABLE_H__
#define __ICOMPARABLE_H__

typedef struct IComparable * PIComparable;
struct IComparable
{
    int (*Compare)(PObject self, PObject other);
    int __offset;
};

#define OOC_IComparable_Compare(self, other) OOC_ICALL((self), Compare), (other) OOC_END_ICALL

#endif
