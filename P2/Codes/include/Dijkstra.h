#ifndef _Dijkstra_H_
#define _Dijkstra_H_

#define MinData -1 //The value of the sentinel node of the smallest heap,H[0]
#define Infinite 1000000000 //Used to initialize 'Dist'
#define NotAVertex -1 //Used to initialize 'Path'
#define False 0 //Means Unknown
#define True 1 //Means Known

#include "HeapElement.h"
#include<fstream>

using namespace std;

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

//Graph related functions
Graph CreateGraph(int v,int e, ifstream& file_in); 
void InsertNewNode(Graph g,int v1,int vertex,int weight); //Insert a new node into an adjacency list
//The key functions of this problem
Table CreateTable(int v,int start);

template<typename MinHeap>
int Dijkstra(int start, int end, MinHeap H, AdjList G, Table T);

/* Method 2 in class: insert vertex with updated Dist into the MinHeap
So T=O(elogv) ; S=O(e) */
template<typename MinHeap>
int Dijkstra(int start, int end, MinHeap H, AdjList G, Table T){
    HeapElement p;
    p.distance=T->Dist[start];
    p.vertex=start;
    H.Insert(p); //Insert the start vertex into heap
    while(H.Size){
        /*Update the information of adjacent vertices 
        from the element with the smallest distance*/
        p=H.DeleteMin(); 
        if(p.vertex == end) return p.distance;
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
                H.Insert(k);
            }
            q=q->Next;
        }
    }
    return -1; //no path between the start vertex and the end vertex
}

void DisplayPath( int start, int end, Table T, ofstream& file_result );

#endif
