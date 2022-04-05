#ifndef _LeftistHeap_H_
#define _LeftistHeap_H_
#define ElementType int

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
private:
    LeftistHeapNode* root;
public:
    LeftistHeap();
    void merge(LeftistHeap* H);
    void Insert(ElementType X);
    ElementType DeleteMin();
private:
    LeftistHeapNode* merge(LeftistHeapNode* H1, LeftistHeapNode* H2);
    LeftistHeapNode* merge1(LeftistHeapNode* H1, LeftistHeapNode* H2);
    LeftistHeapNode* Insert(LeftistHeapNode* H, ElementType X);
    LeftistHeapNode* DeleteMin(LeftistHeapNode* H);
};

#endif