#ifndef _BinaryHeap_H_
#define _BinaryHeap_H_

#define MinData -1
#include "HeapElement.h"
class BinaryHeap
{
public:
    int Capacity;
    int Size;
    ElementType *Elements;

    BinaryHeap(int Capicity);
    int IsEmpty();
    void MakeEmpty();
    void Insert(ElementType X);
    ElementType DeleteMin();
};

#endif