#ifndef _BinaryHeap_H_
#define _BinaryHeap_H_

#define ElementType int

#define MaxN 10000000
#define MinData -1

class BinaryHeap
{
private:
    int Capacity;
    int Size;
    ElementType *Elements;
public:
    BinaryHeap();
    int IsEmpty();
    int IsFull();
    void MakeEmpty();
    void Insert(ElementType X);
    ElementType DeleteMin();
    ElementType FindMin();
};

#endif