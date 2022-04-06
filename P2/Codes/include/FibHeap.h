#ifndef _FIBHEAP_H_
#define _FIBHEAP_H_

#include "HeapElement.h"
#define DH 1000



class FibNode
{
public:
    ElementType Element; //key
    int degree;
    bool mark;
    FibNode* left;
    FibNode* right;
    FibNode* parent;
    FibNode* child;

    FibNode(ElementType Element);
    void InsertToLeft(FibNode* Node);
};

class FibHeap
{
public:
    FibNode* root;
    int Size;

    FibHeap();
    void Insert(ElementType X);
    ElementType DeleteMin();
    void Consolidate();
    void Link(FibNode* child, FibNode* parent);
    void DeleteNode(FibNode* Node);
    void MakeEmpty();
};

#endif