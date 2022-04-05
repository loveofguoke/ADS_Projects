#include<iostream>
#include<string>
#include"../include/SkewHeap.h"
#include<queue>
using namespace std;
void SkewHeap::MergeHeap(SkewHeap* OtherHeap)
{
	Root.root = Merge(Root.root, (OtherHeap)->Root.root);
}
void SkewHeap::MakeEmpty()
{
	queue<SkewHeapNode*> head;
	head.push(Root.root);
	SkewHeapNode* tmp;
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
void SkewHeap::PrintInOrder(SkewHeapNode* H)
{
	if (H != NULL)
	{
		PrintInOrder(H->Left);
		printf("%d ", H->Element);
		PrintInOrder(H->Right);
	}

}
void SkewHeap::PrintLevelOrder()
{
	queue<SkewHeapNode*> head;
	head.push(Root.root);
	SkewHeapNode* tmp;
	while (head.empty() == false)
	{
		tmp = head.front();
		printf("%d ", tmp->Element);
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
	}

}
void SwapChildren(SkewHeapNode* H1)
{
	//Swap Children
	if (H1 != NULL)
	{
		SkewHeapNode* tmp;
		tmp = H1->Left;
		H1->Left = H1->Right;
		H1->Right = tmp;
	}
}

SkewHeapNode* Merge1(SkewHeapNode* H1,SkewHeapNode* H2)
{
	// If H1 is the Single Node
	if (H1->Left == NULL)
	{
		H1->Left = H2;
	}
	else
	{
		H1->Right = Merge(H1->Right, H2);
		SwapChildren(H1);
	}
	return H1;
}
SkewHeapNode* Merge(SkewHeapNode* H1, SkewHeapNode* H2)
{
	//We need to Merge Larger Node to Smaller Node
	if (H1 == NULL) return H2;
	else if (H2 == NULL) return H1;
	else if (H1->Element < H2->Element) return Merge1(H1, H2);
	else return Merge1(H2, H1);
}


void SkewHeap::Insert(ElementType Element)
{
	//Create NewNode
	SkewHeapNode* NewNode = new SkewHeapNode;
	NewNode->Element = Element;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	//Merge with the Heap
	Root.root = Merge(Root.root, NewNode);
}
ElementType SkewHeap::DeleteMin()
{
	ElementType Element;
	//Save the LeftChild and RightChild Of the tree
	SkewHeapNode* LeftChild = Root.root->Left;
	SkewHeapNode* RightChild = Root.root->Right;
	//if heap only has Single node
	if (LeftChild == NULL && RightChild == NULL)
	{
		Element = Root.root->Element;
		delete Root.root;
	}
	else
	{
		Element = Root.root->Element;
		delete Root.root;
		Root.root = Merge(LeftChild, RightChild);
	}
	return Element;
}
//int main()
//{
//	int n;
//	cout << "Heap1" << endl;
//	cin >> n;
//	
//	SkewHeap Heap;
//	Heap.Root.root = NULL;
//	
//	for (int i = 0; i < n; i++)
//	{
//		int tmp;
//		cin >> tmp;
//		Heap.Insert(tmp);
//	}
//	
//	
//	//while (1)
//	//{
//	//	
//	//	Heap.MergeHeap(&Heap1);
//	//	int number=Heap.DeleteMin();
//	//	cout << number << endl;
//	//	Heap.PrintInOrder(Heap.Root.root);
//	//	printf("\n");
//	//	Heap.PrintLevelOrder();
//	//	printf("\n");
//	//	
//	//}
//}