#ifndef _BinaryHeap_H_
#define _BinaryHeap_H_

#define ElementType int

#define MaxN 10000000
#define MinData -1

struct HeapStruct;
typedef struct HeapStruct *BinaryHeap;

int IsEmpty(BinaryHeap H);
int IsFull(BinaryHeap H);
BinaryHeap Initialize(int MaxElements);
void MakeEmpty(BinaryHeap H);
void Insert(ElementType X, BinaryHeap H);
ElementType DeleteMin(BinaryHeap H);
ElementType FindMin(BinaryHeap H);

#endif