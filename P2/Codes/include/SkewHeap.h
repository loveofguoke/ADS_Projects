#pragma once
#define ElementType int
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
public:
	SkewHeap()
	{
		Root.root = NULL;
	}
	void Insert(ElementType Element);
	int DeleteMin();
	void MergeHeap(SkewHeap* OtherHeap);
	void PrintInOrder(SkewHeapNode* H);
	void PrintLevelOrder();
	void MakeEmpty();
};
SkewHeapNode* Merge1(SkewHeapNode* H1, SkewHeapNode* H2);
void SwapChildren(SkewHeapNode* H1);
SkewHeapNode* Merge(SkewHeapNode*H1, SkewHeapNode* H2);