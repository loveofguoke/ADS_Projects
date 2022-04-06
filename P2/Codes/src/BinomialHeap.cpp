#include<iostream>
#include<fstream>
#include <sstream>
#include"../include/BinomialHeap.h"

using namespace std;

void BinomialHeap::MakeEmpty()
{
	for (int i = 0; i < H.Capacity; i++)
	{
		free(H.TheTrees[i]);
	}
}
void BinomialHeap::initialize(int Capacity)
{
	H.TheTrees = new BinNode * [Capacity];
	for (int i = 0; i < MaxTrees; i++)
	{
		H.TheTrees[i] = NULL;
	}
}

BinQueue Initialize(int Capacity)
{
	BinQueue NewHeap = new Collection;
	NewHeap->Capacity = Capacity;
	NewHeap->CurrentSize = 0;
	NewHeap->TheTrees = new BinNode * [Capacity];
	for (int i = 0; i < MaxTrees; i++)
	{
		NewHeap->TheTrees[i] = NULL;
	}
	return NewHeap;
}

BinTree CombineTrees(BinTree T1, BinTree T2)
{
	if (T1->Element > T2->Element)
		return CombineTrees(T2, T1);
	T2->NextSibbling = T1->Left;
	T1->Left = T2;
	return T1;
}
void BinomialHeap:: Insert(ElementType Number)
{
	BinomialHeap* NewHeap = new BinomialHeap(1);
	//Create a one node heap
	NewHeap->H.Capacity = 1;
	NewHeap->H.CurrentSize = 1;
	NewHeap->Size = 1;
	//Create A Node
	BinNode* NewNode = new BinNode;
	NewNode->Element = Number;
	NewNode->Left = NewNode->NextSibbling = NULL;

	NewHeap->H.TheTrees = new BinNode*;
	NewHeap->H.TheTrees[0] = NewNode;
	this->Size++;
	H=*(Merge1(&H,&(NewHeap->H)));
}
void BinomialHeap::Merge(BinQueue H2)
{
	this->Size+=H2->CurrentSize;
	H = *(Merge1(&H, H2));
}
BinQueue Merge1(BinQueue H1,BinQueue H2)
{
	BinTree T1, T2, Carry = NULL;
	int i, j;
	if (H1->CurrentSize + H2->CurrentSize > H1->Capacity)
	{
		//cout << "Out of Size" << endl;
	}
	H1->CurrentSize += H2->CurrentSize;
	for (i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2)
	{
		T1 = H1->TheTrees[i];
		if (i < H2->Capacity)T2 = H2->TheTrees[i];
		else T2 = NULL;
		switch (4 * !!Carry + 2 * !!T2 + !!T1)
		{
		//000
		case 0:
		//001
		case 1:
			break;
		//010
		case 2:
			H1->TheTrees[i] = T2;
			H2->TheTrees[i] = NULL;
			break;
		//011
		case 3:
			Carry = CombineTrees(T1, T2);
			H1->TheTrees[i] = H2->TheTrees[i] = NULL;
			break;
		//100;
		case 4:
			H1->TheTrees[i] = Carry;
			Carry = NULL;
			break;
		//101
		case 5:
			Carry = CombineTrees(T1, Carry);
			H1->TheTrees[i] = NULL;
			break;
		//110
		case 6:
			Carry = CombineTrees(T2, Carry);
			H2->TheTrees[i] = NULL;
			break;
		//111
		case 7:
			H1->TheTrees[i] = Carry;
			Carry = CombineTrees(T1, T2);
			H2->TheTrees[i] = NULL;
			break;
		}
	}
	return H1;
}
bool IsEmpty(BinQueue H)
{
	if (H->CurrentSize == 0) return true;
	else return false;
}
ElementType BinomialHeap::DeleteMin()
{
	BinQueue DeletedQueue;
	Position DeletedTree, OldRoot;
	//initialized MinItem
	ElementType MinItem;
	MinItem.distance = INT_MAX;
	MinItem.vertex = -1;
	//Deleted one node from Heap , the size of heap decremented.
	int i, j, MinTree;
	this->Size--;
	if (IsEmpty(&H))
	{
		cout << "Priority Queue is Empty" << endl;

	}
	//Step1: find the minimum item
	for (i = 0; i < H.Capacity; i++)
	{
		if (H.TheTrees[i] && H.TheTrees[i]->Element < MinItem)
		{
			MinItem = H.TheTrees[i]->Element;
			MinTree = i;
		}
	}
	
	DeletedTree = H.TheTrees[MinTree];
	//Step2: Remove the MinTree from H
	H.TheTrees[MinTree] = NULL;
	OldRoot = DeletedTree;
	DeletedTree = DeletedTree->Left;
	free(OldRoot);
	DeletedQueue = Initialize(MaxTrees);
	//Create New Heap
	DeletedQueue->CurrentSize = (1 << MinTree) - 1;
	for (j = MinTree - 1; j >= 0; j--)
	{
		DeletedQueue->TheTrees[j] = DeletedTree;
		DeletedTree = DeletedTree->NextSibbling;
		DeletedQueue->TheTrees[j]->NextSibbling = NULL;
	}
	H.CurrentSize -= DeletedQueue->CurrentSize + 1;
	H = *(Merge1(&H,DeletedQueue));
	return MinItem;
}
//int read(string FileName)
//{
//
//	std::ifstream fin;
//	int cnt = 0;
//	fin.open(FileName, std::ios::in);
//	if (!fin)
//	{
//		cout << "锟斤拷失锟斤拷" << endl;
//		return false;
//	}
//	char line[1024] = { 0 };
//	while (fin.getline(line, sizeof(line)))
//	{
//		string TextContent = line;
//		////锟斤拷取一锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷
//		std::stringstream word(line);
//		int Distance;
//		word >> Distance;	
//		cnt++;
//		cout << TextContent << endl;
//	}
//	return cnt;
//}


//int main()
//{
//	cout << "Give File full path" << endl;
//	cout << "such as D:\\data.txt " << endl;
//	string FileName;
//	cin >> FileName;
//	int n;
//	n = read(FileName);
//	BinomialHeap H(MaxTrees);
//	read(FileName, H);
//	
//	for (int i = 0; i < n; i++)
//	{
//		int tmp;
//		tmp = H.DeleteMin();
//		cout << tmp << endl;
//	}
//	
//	MakeEmpty(H);
//
//}