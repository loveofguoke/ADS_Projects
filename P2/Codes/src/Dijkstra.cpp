#include<iostream>
#include <fstream>
#include <stack>
#include "../include/Dijkstra.h"

#define MinData -1 //The value of the sentinel node of the smallest heap,H[0]
#define Infinite 1000000000 //Used to initialize 'Dist'
#define NotAVertex -1 //Used to initialize 'Path'
#define False 0 //Means Unknown
#define True 1 //Means Known

using namespace std;

/* The railway is from v1 to v2, and the length of it is weight  */
void InsertNewNode(Graph g,int v1,int v2,int weight){
    //Update adjacency lists   
    PtrToAdjVNode p = new AdjVNode;//Create a new AdjVNode
    p->vertex=v2;
    p->weight=weight;
    //Insert into the head of the adjacency list of v1
    p->Next=g->G[v1];
    g->G[v1]=p;
    //Update inverse adjacency lists
    PtrToAdjVNode q = new AdjVNode;
    q->vertex=v1;
    q->weight=weight;
    //Insert into the head of the inverse adjacency list of v2
    q->Next=g->RG[v2];
    g->RG[v2]=q;
}

Graph CreateGraph(int v, int e, ifstream& file_in)
{
    int i;
    Graph p = new GraphRecord;
    p->G = new PtrToAdjVNode[v+1]; //The sequence number of vertices starts with 1
    p->RG = new PtrToAdjVNode[v+1];
    p->v=v; //Update the information of graph
    p->e=e;
    for(i = 1; i <= v; i++ )
    {
        p->G[i]=nullptr; //Initialize the adjacency lists as an empty linked lists
        p->RG[i]=nullptr;
    }
    for(i = 0; i < e; i++)
    {
        int v1, v2, weight;
        //Read the edges one by one and insert them into the adjacency lists
        file_in >> v1 >> v2 >> weight;
        InsertNewNode(p,v1,v2,weight);
    }
    return p;
}

Table CreateTable(int v,int start){
    int i;
    Table T= new TableStruct;
    //ALL start with the array index 1
    T->Dist= new int[v+1];  
    T->Path= new int[v+1];
    T->Known= new int[v+1];
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

void DisplayPath( int start, int end, Table T, ofstream& file_result )
{
    stack<int> path;
    int index = end;
    while(index != start)
    {
        path.push(index);
        index = T->Path[index];
    }
    path.push(start);
        
    cout << "The shortest path is: " ;
    while(!path.empty())
    {
        index = path.top();
        path.pop();
        file_result << index << " " ;
    }
}

