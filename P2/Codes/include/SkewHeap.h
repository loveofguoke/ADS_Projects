#pragma once

#include "HeapElement.h"
struct SkewHeapNode
{
	ElementType Element;
	SkewHeapNode * Left;
	SkewHeapNode * Right;
};
struct SkewHeapRoot
{
	SkewHeapNode* root;
	
};

class SkewHeap
{
public:
	SkewHeapRoot Root;
	int Size;
public:
	SkewHeap()
	{
		Root.root = NULL;
		this->Size = 0;
	}
	void Insert(ElementType Element);
	ElementType DeleteMin();
	void MergeHeap(SkewHeap* OtherHeap);
	void PrintInOrder(SkewHeapNode* H);
	void PrintLevelOrder();
	void MakeEmpty();
};
SkewHeapNode* Merge1(SkewHeapNode* H1, SkewHeapNode* H2);
void SwapChildren(SkewHeapNode* H1);
SkewHeapNode* Merge(SkewHeapNode*H1, SkewHeapNode* H2);