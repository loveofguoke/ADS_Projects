#ifndef _LeftistHeap_H_
#define _LeftistHeap_H_
#define ElementType int

struct TreeNode;
typedef struct TreeNode *LeftistHeap;

LeftistHeap Merge(LeftistHeap H1, LeftistHeap H2);
static LeftistHeap Merge1(LeftistHeap H1, LeftistHeap H2);
static void SwapChildren(LeftistHeap H);
LeftistHeap Insert(ElementType X, LeftistHeap H);
LeftistHeap DeleteMin(LeftistHeap H);
ElementType FindMin(LeftistHeap H);

#endif