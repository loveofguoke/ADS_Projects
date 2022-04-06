#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "../include/BinaryHeap.h"


using namespace std;

class BinaryHeap;

BinaryHeap::BinaryHeap(int Capacity)
{
    this->Capacity = Capacity + 1;
    Size = 0;
    Elements = new ElementType[Capacity+1]; //begin at H[1]
    Elements[0].distance = MinData;
}

int BinaryHeap::IsEmpty() 
{
    if(Size == 0) return 1;
    return 0;
}

void BinaryHeap::MakeEmpty()
{
    delete[] Elements;
    Size = 0;
}

void BinaryHeap::Insert(ElementType X)
{
    int i;
    for( i = ++Size; Elements[i/2] > X; i /= 2)
        Elements[i] = Elements[i/2];
    Elements[i] = X;
}

ElementType BinaryHeap::DeleteMin()
{
    if(IsEmpty()){
        printf("Heap is empty");
        return {-1, -1};
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

