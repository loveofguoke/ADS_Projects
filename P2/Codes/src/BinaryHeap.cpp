#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "../include/BinaryHeap.h"

using namespace std;

class BinaryHeap;

BinaryHeap::BinaryHeap()
{
    Capacity = MaxN;
    Size = 0;
    Elements = (ElementType *)malloc(sizeof(ElementType) * MaxN);
    Elements[0] = MinData;
}

int BinaryHeap::IsEmpty() 
{
    if(Size == 0) return 1;
    return 0;
}

int BinaryHeap::IsFull() 
{
    if(Size == Capacity) return 1;
    return 0;
}

void BinaryHeap::MakeEmpty()
{
    free(Elements);
    Capacity = MaxN;
    Size = 0;
    Elements = (ElementType *)malloc(sizeof(ElementType) * MaxN);
}

void BinaryHeap::Insert(ElementType X)
{
    int i;
    if(IsFull())
    {
        printf("Heap is full");
        return ;
    }
    for( i = ++Size; Elements[i/2] > X; i /= 2)
        Elements[i] = Elements[i/2];
    Elements[i] = X;
}

ElementType BinaryHeap::DeleteMin()
{
    if(IsEmpty()){
        printf("Heap is empty");
        return MinData;
    }
    ElementType Min, Last;
    Min = Elements[1];
    Last = Elements[Size --];

    int i, Child;
    for(i=1; i*2 <= Size; i = Child)
    {
        Child = i * 2;
        if(Child != Size && Elements[Child] > Elements[Child + 1])
            ++ Child;
        if(Last > Elements[Child])
            Elements[i] = Elements[Child];
        else break;
    }
    Elements[i] = Last;

    return Min;
}

ElementType BinaryHeap::FindMin()
{
    if(IsEmpty()){
        printf("Heap is empty");
        return MinData;
    }
    return Elements[1];
}