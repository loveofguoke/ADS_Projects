#pragma once
#define MaxTrees 100
#include "HeapElement.h"
struct BinNode
{
	ElementType Element;
	BinNode* Left;
	BinNode* NextSibbling;

};
class Collection
{
public:
	int Capacity;
	int CurrentSize;
	BinNode** TheTrees;
public:
	Collection()
	{
		CurrentSize = 0;
		Capacity = MaxTrees;
		TheTrees = NULL;
	}
};
typedef struct BinNode* Position;
typedef struct Collection* BinQueue;
typedef struct BinNode* BinTree;
class BinomialHeap
{
public:
	Collection H;
	int Size;
	BinomialHeap()
	{
		Size = 0;
		H.CurrentSize = 0;
		H.Capacity = MaxTrees;
		H.TheTrees = NULL;
	}
	BinomialHeap(int Capacity)
	{
		Size = 0;
		H.CurrentSize = 0;
		H.Capacity = Capacity;
		H.TheTrees = new BinNode * [Capacity];
		for (int i = 0; i < Capacity; i++)
		{
			H.TheTrees[i] = NULL;
		}
	}
	void initialize(int Capacity);
	void Insert(ElementType Number);
	void Merge(BinQueue H2);
	ElementType DeleteMin();
	void MakeEmpty();

};

BinQueue Merge1(BinQueue H1, BinQueue H2);
bool IsEmpty(BinQueue H);