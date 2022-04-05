#include<stdio.h>
#include<stdlib.h>
#define MinData -1 //The value of the sentinel node of the smallest heap,H[0]
#define Infinite 1000000000 //Used to initialize 'Dist'
#define NotAVertex -1 //Used to initialize 'Path'
#define False 0 //Means Unknown
#define True 1 //Means Known

//General definition of stacks
typedef struct StackRecord *Stack;
struct StackRecord{
    int top;    //-1 for empty stack
    int *content;
    int Capacity; //Maximum Capacity
};

//Definition of Heap
/* Each element in the heap is a structure that stores 
the sequence number and distance of a vertex */
typedef struct{
    int vertex;
    int distance;
}HeapElement;

typedef struct HeapStruct *MinHeap;
struct HeapStruct{
    HeapElement *Elements; //A structural array that stores heap elements
    int Size; //Number of current elements
    int Capacity; //Maximum Capacity
};

//Definition of Graph
typedef struct AdjVNode *PtrToAdjVNode; 
//Nodes in adjacency list
struct AdjVNode{
    int vertex; 
    int weight; //Distance between two vertexs
    PtrToAdjVNode Next;
};

typedef PtrToAdjVNode* AdjList; //Adjacency lists
typedef struct GraphRecord *Graph;
struct GraphRecord{  
    int v; //Number of vertexs in the graph
    int e; //Number of edges in the graph
    AdjList G; //Adjacency lists
    AdjList RG; //Inverse adjacency lists
};

//The structure needed to find the shortest path
typedef struct TableStruct *Table;
struct TableStruct{
    int *Dist; //The distance between this vertex and the start vertex 
    int *Path; //Stores the previous vertex of the current vertex on the shortest path
    int *Known; //Indicates whether the shortest path has been found for this vertex
};

//Function declaration
//Stack related functions
Stack CreateStack(int v); //Create a new stack
void Push(Stack S,int X);
int Pop(Stack S);
int IsemptyS(Stack S); //Judge if the stack is empty
//Heap related functions
MinHeap CreateHeap(int Capacity); //Create a new heap
void Insert(MinHeap H,HeapElement item); //Insert a new element into the heap
int IsEmptyH(MinHeap H);
HeapElement DeleteMin(MinHeap H); //Delete and return the minimum element
//Graph related functions
Graph CreateGraph(int v,int e); 
void InsertNewNode(Graph g,int v1,int vertex,int weight); //Insert a new node into an adjacency list
//The key functions of this problem
Table CreateTable(int v,int start);
void Dijkstra(int start,MinHeap H,AdjList G,Table T); //Dijkstra's Algorithm in class
void Second_Shortest_Path(int start,int end,Stack S,Graph g,Table T);

int main(){
    int M,N;
    scanf("%d%d",&M,&N); //Gets the number of vertexs and edges of the graph
    Graph g=CreateGraph(M,N); //Create the graph showing stations and railways
    MinHeap H=CreateHeap(N); //Used to find the shortest path
    Stack S=CreateStack(M+2); //For output the path in positive order
    Table T=CreateTable(M,1); //Used in Dijkstra's Algorithm
    Dijkstra(1,H,g->G,T); //Find the shortest path first
    //If there is no way back home,end the program
    if(T->Dist[M]==Infinite){
        printf("I'm sorry that Lisa can't go home now.");
        return 0;
    } 
    /*Use the information of shortest path to find the
    second-shortest path */
    Second_Shortest_Path(1,M,S,g,T);  
    return 0;
}

Stack CreateStack(int n){
    Stack S=malloc(sizeof(struct StackRecord));
    S->content=malloc(sizeof(int)*n);
    S->Capacity=n; 
    S->top=-1; //Initialize to empty stack
    return S;
}

void Push(Stack S,int X){
    S->content[++S->top]=X; //top always point to the top element
}

int Pop(Stack S){
    return S->content[S->top--];
}

int IsemptyS(Stack S){
    if(S->top==-1) return 1;
    else return 0;
}


MinHeap CreateHeap(int Capacity){
    MinHeap H=malloc(sizeof(struct HeapStruct));
    H->Elements=malloc(sizeof(HeapElement)*(Capacity+1)); //begin at H[1]
    H->Capacity=Capacity+1;
    H->Size=0; //Initialize to empty heap
    H->Elements[0].distance=MinData; //Set the sentinel of the heap
    return H;
}

void Insert(MinHeap H,HeapElement Newone)  //O(logv)
{	//H->Elements[0] is the sentinel
    int i;
    i=++H->Size;
    //Percolate up
    for(;H->Elements[i/2].distance>Newone.distance;i/=2)//Compare with parent node
        H->Elements[i]=H->Elements[i/2];//Smaller than the parent node, the parent node moves down
    H->Elements[i]=Newone;//Larger than the parent node, insert at this location
}

int IsEmptyH(MinHeap H){
    if(H->Size==0) return 1;
    else return 0;
}

HeapElement DeleteMin(MinHeap H){ //O(logv)
    int i,Child; 
    HeapElement Minone,Lastone; 
    Minone = H->Elements[1]; // save the min element 
    Lastone = H->Elements[H->Size--]; // take last one and reset size 
    for (i=1;i*2<=H->Size;i=Child){  // Find smaller child 
         Child = i*2; 
         if (Child != H->Size && H->Elements[Child+1].distance < H->Elements[Child].distance) 
	        Child++;     
         //Percolate down
         if (Lastone.distance > H->Elements[Child].distance)   
	       	H->Elements[i] = H->Elements[Child];   
         else break;   // find the proper position
    } 
    H->Elements[i] = Lastone;  //Readjusted to minimum heap
    return Minone; 
}

/* The railway is from v1 to v2, and the length of it is weight  */
void InsertNewNode(Graph g,int v1,int v2,int weight){
    //Update adjacency lists   
    PtrToAdjVNode p=malloc(sizeof(struct AdjVNode));//Create a new AdjVNode
    p->vertex=v2;
    p->weight=weight;
    //Insert into the head of the adjacency list of v1
    p->Next=g->G[v1];
    g->G[v1]=p;
    //Update inverse adjacency lists
    PtrToAdjVNode q=malloc(sizeof(struct AdjVNode));
    q->vertex=v1;
    q->weight=weight;
    //Insert into the head of the inverse adjacency list of v2
    q->Next=g->RG[v2];
    g->RG[v2]=q;
}

Graph CreateGraph(int v,int e){
    int i;
    Graph p=malloc(sizeof(struct GraphRecord));
    p->G=malloc(sizeof(PtrToAdjVNode)*(v+1));//The sequence number of vertices starts with 1
    p->RG=malloc(sizeof(PtrToAdjVNode)*(v+1));
    p->v=v;//Update the information of graph
    p->e=e;
    for(i=1;i<=v;i++){
        p->G[i]=NULL;//Initialize the adjacency lists as an empty linked lists
        p->RG[i]=NULL;
    }
    for(i=0;i<e;i++){
        int v1,v2,weight;
        //Read the edges one by one and insert them into the adjacency lists
        scanf("%d%d%d",&v1,&v2,&weight);
        InsertNewNode(p,v1,v2,weight);
    }
    return p;
}

Table CreateTable(int v,int start){
    int i;
    Table T=malloc(sizeof(struct TableStruct));
    //ALL start with the array index 1
    T->Dist=malloc(sizeof(int)*(v+1)); 
    T->Path=malloc(sizeof(int)*(v+1));
    T->Known=malloc(sizeof(int)*(v+1));
    //Initialize information to unknown before finding
    for(i=1;i<=v;i++){
        T->Dist[i]=Infinite;
        T->Path[i]=NotAVertex;
        T->Known[i]=False;
    }
    //The starting vertex is the algorithm entry
    T->Dist[start]=0;
    return T;
}

/* Method 2 in class: insert vertex with updated Dist into the MinHeap
So T=O(elogv) ; S=O(e) */
void Dijkstra(int start,MinHeap H,AdjList G,Table T){
    HeapElement p;
    p.distance=T->Dist[start];
    p.vertex=start;
    Insert(H,p); //Insert the start vertex into heap
    while(H->Size){
        /*Update the information of adjacent vertices 
        from the element with the smallest distance*/
        p=DeleteMin(H); 
        T->Known[p.vertex]=True; //Shortest path found
        PtrToAdjVNode q=G[p.vertex];
        //for each vertex adjacent to p.vertex
        while(q){
            int adjacent=q->vertex;
            /* If the shortest path of the adjacent vertex has
            been found, there is no need to update its information */
            if(T->Known[adjacent]==True) {
                q=q->Next;
                continue;
            }
            int distance=q->weight+p.distance;
            if(distance<T->Dist[adjacent]){
                /* Update the information */
                T->Dist[adjacent]=distance;
                T->Path[adjacent]=p.vertex;
                /* Insert the new information to heap
                help other vertex update information */
                HeapElement k;
                k.vertex=adjacent;
                k.distance=distance;
                Insert(H,k);
            }
            q=q->Next;
        }
    }
}

// Find the second-shortest path from the start vertex to the end vertex 
void Second_Shortest_Path(int start,int end,Stack S,Graph g,Table T){
    int i;
    int Local_End; //The end vertex of local shortest path 
    int Global_Begin; //The start vertex of global shortest path
    int Second_Shortest_Length=Infinite;
    int Shortest_Length=T->Dist[end]; //The length of the shortest path
    /* Since the second-shortest path consists of local shortest path and
    global shortest path,we only need to traverse each vertex Vi on the global
    shortest path. Calculate the local shortest path length of each vertex Vik
    pointing to Vi, plus the side length (vi,vik), plus the path length from
    Vi to the end vertex. In this way, the path length connected by the local
    shortest path and the global shortest path is calculated. From these paths,
    the path that is only longer than the global shortest path is the second shortest path. */
    for(i=end;;i=T->Path[i]){
        PtrToAdjVNode p=g->RG[i];
        while(p){
            int length=p->weight+T->Dist[p->vertex]+(T->Dist[end]-T->Dist[i]);
            if(length<Second_Shortest_Length&&length>Shortest_Length){
                Second_Shortest_Length=length;
                Local_End=p->vertex;
                Global_Begin=i;
            }
            p=p->Next;
        }
        if(T->Path[i]==NotAVertex) break;
    }
    //If there is no second-shortest path, return directly
    if(Second_Shortest_Length==Infinite){
        printf("Lisa can only go home by the shortest path.");
        return;
    }
    //Out put the second-shortest path in positive order with stack
    printf("%d",Second_Shortest_Length);
    //The global shortest path part
    for(i=end;i!=Global_Begin;i=T->Path[i]){
        Push(S,i);
    }
    Push(S,Global_Begin);
    //The local shortest path part
    for(i=Local_End;i!=start;i=T->Path[i]){
        Push(S,i);
    }
    Push(S,start);
    while(!IsemptyS(S)){
        int k=Pop(S);
        printf(" %d",k);
    }    
}

