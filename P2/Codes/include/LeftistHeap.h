#ifndef _LeftistHeap_H_
#define _LeftistHeap_H_

#include "HeapElement.h"
class LeftistHeapNode
{
public:
    ElementType Element;
    LeftistHeapNode* Left;
    LeftistHeapNode* Right;
    int Npl;

};

class LeftistHeap
{
public:
    LeftistHeapNode* root;
    int Size;

    LeftistHeap();
    void merge(LeftistHeap* H);
    LeftistHeapNode* Insert(ElementType X);
    ElementType DeleteMin();
    void MakeEmpty();

private:
    LeftistHeapNode* merge(LeftistHeapNode* H1, LeftistHeapNode* H2);
    LeftistHeapNode* merge1(LeftistHeapNode* H1, LeftistHeapNode* H2);
    LeftistHeapNode* Insert(LeftistHeapNode* H, ElementType X);
    LeftistHeapNode* DeleteMin(LeftistHeapNode* H);
};

#endif
