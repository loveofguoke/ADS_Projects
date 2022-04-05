#pragma once
#define MaxTrees 100000
#define ElementType int
struct BinNode
{
	ElementType Element;
	BinNode* Left;
	BinNode* NextSibbling;

};
class Collection
{
public:
	int CurrentSize;
	int Capacity;
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
public:
	BinomialHeap()
	{
		H.CurrentSize = 0;
		H.Capacity = MaxTrees;
		H.TheTrees = NULL;
	}
	BinomialHeap(int Capacity)
	{
		H.CurrentSize = 0;
		H.Capacity = Capacity;
		H.TheTrees = new BinNode * [Capacity];
		for (int i = 0; i < Capacity; i++)
		{
			H.TheTrees[i] = NULL;
		}
	}
	void DecreaseKey(BinNode* Node, int val);
	void initialize(int Capacity);
	void Insert(ElementType Number);
	void Merge(BinQueue H2);
	ElementType DeleteMin();

};

BinQueue Merge1(BinQueue H1, BinQueue H2);
bool IsEmpty(BinQueue H);
void MakeEmpty(BinomialHeap& Heap);