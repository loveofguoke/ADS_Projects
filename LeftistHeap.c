#include <stdio.h>
#include <stdlib.h>

#include "LeftistHeap.h"

struct TreeNode
{
    ElementType Element;
    LeftistHeap Left;
    LeftistHeap Right;
    int Npl;
};

LeftistHeap Merge(LeftistHeap H1, LeftistHeap H2)
{
	if(H1 == NULL)
		return H2;
	if(H2 == NULL)
		return H1;
	if(H1->Element < H2->Element)
		return Merge1(H1, H2);
	else
		return Merge1(H2, H1);
}

static LeftistHeap Merge1(LeftistHeap H1, LeftistHeap H2)
{
	if(H1->Left == NULL)
		H1->Left = H2;
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if(H1->Left->Npl < H1->Right->Npl)
			SwapChildren(H1);
		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}

static void SwapChildren(LeftistHeap H)
{
    LeftistHeap temp;
    temp = H->Left;
    H->Left = H->Right;
    H->Right = temp;
    free(temp);
}

LeftistHeap Insert(ElementType X, LeftistHeap H)
{
	LeftistHeap SingleNode;
	SingleNode = (LeftistHeap)malloc(sizeof(struct TreeNode));
	if(SingleNode == NULL)
		printf("Out of Space!!!");
	else
	{
		SingleNode->Element = X;
		SingleNode->Left = SingleNode->Right = NULL;
		SingleNode->Npl = 0;
		H = Merge(SingleNode, H);
	}
	return H;
}

LeftistHeap DeleteMin(LeftistHeap H)
{
	LeftistHeap LeftHeap, RightHeap;
	if(H == NULL)
	{
		printf("Heap is Empty");
		return H;
	}
	else
	{
		LeftHeap = H->Left;
		RightHeap = H->Right;
		free(H);
		return Merge(LeftHeap, RightHeap);
	}
}

ElementType FindMin(LeftistHeap H)
{
	return H->Element;
}