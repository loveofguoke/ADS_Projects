#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>

#include "../include/LeftistHeap.h"

using namespace std;

class LeftistHeapNode;
class LeftistHeap;

LeftistHeap::LeftistHeap()
{
	root = (LeftistHeapNode *)malloc(sizeof(LeftistHeapNode));
	root = NULL;
	Size = 0;
}

void LeftistHeap::merge(LeftistHeap* H)
{
	root = merge(root, H->root);
}

void LeftistHeap::Insert(ElementType X)
{
	root = Insert(root, X);
	++ Size;
}

ElementType LeftistHeap::DeleteMin()
{
	ElementType temp = root->Element;
	root = DeleteMin(root);
	-- Size;
	return temp;
}

LeftistHeapNode* LeftistHeap::merge(LeftistHeapNode* H1, LeftistHeapNode* H2)
{
	if(H1 == NULL) return H2;
	if(H2 == NULL) return H1;
	if(H1->Element < H2->Element) return merge1(H1, H2);
	else return merge1(H2, H1);
}

LeftistHeapNode* LeftistHeap::merge1(LeftistHeapNode* H1, LeftistHeapNode* H2)
{
	if(H1->Left == NULL) H1->Left = H2;
	else{
		H1->Right = merge(H1->Right, H2);
		if(H1->Left->Npl > H2->Left->Npl){
			LeftistHeapNode* temp = H1->Left;
			H1->Left = H1->Right;
			H1->Right = temp;
		}
	}
	return H1;
}

LeftistHeapNode* LeftistHeap::Insert(LeftistHeapNode* H, ElementType X)
{
	LeftistHeapNode* SingleNode;
	SingleNode = (LeftistHeapNode*)malloc(sizeof(LeftistHeapNode));
	
	if(SingleNode == NULL){
		printf("Out of space!");
		return NULL;
	}
	else{
		SingleNode->Element = X;
		SingleNode->Left = SingleNode->Right = NULL;
		SingleNode->Npl = 0;
		H = merge(H, SingleNode);
	}
	return H;
}

LeftistHeapNode* LeftistHeap::DeleteMin(LeftistHeapNode* H)
{
	if(H == NULL){
		printf("Heap is empty.");
		return NULL;
	}
	LeftistHeapNode* LeftHeap,* RightHeap;
	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return merge(LeftHeap, RightHeap);
}

void LeftistHeap::MakeEmpty()
{
	queue<LeftistHeapNode*> head;
	head.push(root);
	LeftistHeapNode* tmp;
	while (head.empty() == false)
	{
		tmp = head.front();
		head.pop();
		if (tmp != NULL)
		{
			if (tmp->Left != NULL)
			{
				head.push(tmp->Left);
			}
			if (tmp->Right != NULL)
			{
				head.push(tmp->Right);
			}
		}
		delete tmp;
	}
}
