#include <stdio.h>
#include <stdlib.h>

#include "BinaryHeap.h"

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};

int IsEmpty(BinaryHeap H)
{
    if(H->Size == 0) return 1;
    return 0;
}

int IsFull(BinaryHeap H)
{
    if(H->Size == H->Capacity) return 1;
    return 0;
}

BinaryHeap Initialize(int MaxElements)
{
    BinaryHeap H;
    H = (BinaryHeap)malloc(sizeof(struct HeapStruct));
    if(H == NULL) printf("Out of space!");

    H->Elements = (ElementType *)malloc((MaxElements + 1)*sizeof(ElementType));
    if(H->Elements == NULL) printf("Out of space!");

    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;
    return H;
}

void MakeEmpty(BinaryHeap H)
{
    free(H->Elements);
    free(H);
}

void Insert(ElementType X, BinaryHeap H)
{
    int i;
    if(IsFull(H))
    {
        printf("Heap is full");
        return ;
    }
    for( i = ++H->Size; H->Elements[i/2] > X; i /= 2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = X;
}

ElementType DeleteMin(BinaryHeap H)
{
    if(IsEmpty(H)){
        printf("Heap is empty");
        return MinData;
    }
    ElementType Min, Last;
    Min = H->Elements[1];
    Last = H->Elements[H->Size --];

    int i, Child;
    for(i=1; i*2 <= H->Size; i = Child)
    {
        Child = i * 2;
        if(Child != H->Size && H->Elements[Child] > H->Elements[Child + 1])
            ++ Child;
        if(Last > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else break;
    }
    H->Elements[i] = Last;

    return Min;
}

ElementType FindMin(BinaryHeap H)
{
    if(IsEmpty(H)){
        printf("Heap is empty");
        return MinData;
    }
    return H->Elements[1];
}