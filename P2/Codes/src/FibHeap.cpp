#include<iostream>
#include"../include/FibHeap.h"


using namespace std;

FibNode::FibNode(ElementType Element)
    : Element(Element), degree(0), mark(false), 
      parent(nullptr), child(nullptr), left(this), right(this)
    {}

void FibNode::InsertToLeft(FibNode* Node)
{
    Node->left = this->left;
    Node->right = this;
    this->left->right = Node;
    this->left = Node;
}

FibHeap::FibHeap()
    : root(nullptr), Size(0) 
    {}

void FibHeap::Insert(ElementType X)
{
    FibNode* NewNode = new FibNode(X);
    if(root == nullptr) root = NewNode;
    else
    {
        //插到根指针指向的结点左边
        root->InsertToLeft(NewNode);

        if(NewNode->Element.distance < root->Element.distance) root = NewNode;
    }
    Size++;
}

ElementType FibHeap::DeleteMin()
{
    FibNode* Min = root;
    FibNode* p;
    ElementType temp = {-1,-1};

    if(Min != nullptr)
    {
        //将最小结点的每个孩子变为根链结点，只要将孩子链插入根链即可
        if(Min->child)
        {
            for(p = Min->child; p->parent; p = p->right) p->parent = nullptr;
            FibNode* q = root->left;
            p = Min->child;
            root->left->right = p;
            p->left->right = root;
            root->left = p->left;
            p->left = q;
        }
        if(root == root->right) root = nullptr; //仅剩根结点
        else root = root->right;
        //切掉Min
        Min->left->right = Min->right;
        Min->right->left = Min->left;

        if(root != nullptr) Consolidate();
        Size--; 
    }
    else
    {
        cout << "Error! DeleteMin on an empty FibHeap!" << endl;
        return temp;
    } 

    temp = Min->Element;
    delete Min;
    return temp;
}

void FibHeap::Consolidate()
{
    FibNode** A = new FibNode* [DH];
    for(int i = 0; i < DH; i++) A[i] = nullptr;
    FibNode* p = root;
    FibNode* q = nullptr;
    int d = 0;
    int MaxD = 0;
    //遍历根链表，通过拆出来的方式保证最终留在根链上的结点都被遍历1次
    while(p)
    {
        if(p->right == p) q = nullptr; //p是根链上最后一个需要遍历的结点
        else q = p->right;
        //将p从根链移除
        p->left->right = p->right;
        p->right->left = p->left;
        p->left = p->right = p;
        //开始检验已处理的结点中是否有与p度数相同的
        for(d = p->degree; A[d] != nullptr; d++)
        {
            if(p->Element.distance < A[d]->Element.distance) 
                Link(A[d], p);
            else
            {
                Link(p, A[d]);
                p = A[d];
            }
            A[d] = nullptr;
        }
        A[d] = p;
        if(d > MaxD) MaxD = d;

        p = q;
    }
    //全部都分离了，需要重连
    root = nullptr;
    for( int i = 0; i <= MaxD; i++)
    {
        if(A[i] != nullptr)
        {
            if(root == nullptr) root = A[i];
            else root->InsertToLeft(A[i]); //插入根链
            if(A[i]->Element.distance < root->Element.distance)
                root = A[i];
        }
    }
    delete[] A;
}

void FibHeap::Link(FibNode* child, FibNode* parent)
{
    child->parent = parent;
    if(parent->child) parent->child->InsertToLeft(child); //插入子链
    else parent->child = child;
    parent->degree++;
    child->mark = false;
}

void FibHeap::DeleteNode(FibNode* Node)
{
    Node->left->right = nullptr;
    while(Node != nullptr)
    {
        if(Node->child != nullptr) DeleteNode(Node->child);
        FibNode* temp = Node;
        Node = Node->right;
        delete temp;
    }
}

void FibHeap::MakeEmpty()
{
    DeleteNode(root);
    root = nullptr;
    Size = 0;
}

/* for test
int main()
{
    FibHeap H;
    HeapElement a1 = {1,2};
    HeapElement a2 = {2,3};
    HeapElement a3 = {3,6};
    HeapElement a4 = {1,15};
    HeapElement a5 = {2,9};
    HeapElement a6 = {3,0};
    HeapElement a7 = {1,2};
    HeapElement a8 = {2,3};
    HeapElement a9 = {3,6};
    HeapElement a10 = {1,15};
    HeapElement a11 = {2,9};
    HeapElement a12 = {3,0};
    H.Insert(a1);
    H.Insert(a2);
    H.Insert(a3);
    H.Insert(a4);
    H.Insert(a5);
    H.Insert(a6);
    H.Insert(a7);
    H.Insert(a8);
    H.Insert(a9);
    H.Insert(a10);
    H.Insert(a11);
    H.Insert(a12);
   HeapElement t = H.DeleteMin();
    cout << t.distance << endl;
    t = H.DeleteMin();
    cout << t.distance << endl; 

     t = H.DeleteMin();
    cout << t.distance << endl; 
     t = H.DeleteMin();
    cout << t.distance << endl; 
    t = H.DeleteMin();
    cout << t.distance << endl; 
    t = H.DeleteMin();
    cout << t.distance << endl; 
    H.MakeEmpty();
    cout << "------------------" << endl;
    H.Insert(a1);
    H.Insert(a2);
    H.Insert(a3);
    H.Insert(a4);
    H.Insert(a5);
    H.Insert(a6);
    H.Insert(a7);
    H.Insert(a8);
    H.Insert(a9);
    H.Insert(a10);
    H.Insert(a11);
    H.Insert(a12);
    t = H.DeleteMin();
    cout << t.distance << endl;
    t = H.DeleteMin();
    cout << t.distance << endl; 

     t = H.DeleteMin();
    cout << t.distance << endl; 
     t = H.DeleteMin();
    cout << t.distance << endl; 
    t = H.DeleteMin();
    cout << t.distance << endl; 
    t = H.DeleteMin();
    cout << t.distance << endl; 
    t = H.DeleteMin();
    cout << t.distance << endl;
    t = H.DeleteMin();
    cout << t.distance << endl; 

     t = H.DeleteMin();
    cout << t.distance << endl; 
     t = H.DeleteMin();
    cout << t.distance << endl; 
    t = H.DeleteMin();
    cout << t.distance << endl; 
    t = H.DeleteMin();
    cout << t.distance << endl; 
}
*/