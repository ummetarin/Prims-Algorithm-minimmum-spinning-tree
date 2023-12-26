#include<iostream>
#include<limits.h>
#define V 5

int minKey(int key[],bool setKey[]){
    int min_value=INT_MAX;
    int min_index;
    // v=all vertex
    for(int v=0;v<V;v++){
        if(!setKey[v] && key[v]<min_value){
            min_value=key[v];
            min_index=v;
        }
    }
    return min_index;
}

// print the edges of details in the minimum spanning tree

void printMst(int parent[],int graph[V][V]){
    for(int i=1;i<V;i++){
        std::cout<<parent[i]<<"-"<<i<<"  "<<graph[i][parent[i]]<<'\n';
    }
}

void primeMst(int graph[V][V]){
    int parent[V] = {-1};
    int key[V];
    bool setKey[V]={false};
    key[0]=0;

    for(int i=0;i<V-1;i++){
        int u=minKey(key,setKey);
        setKey[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v] && !setKey[v] && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }

    printMst(parent,graph);
}

int main(){
    int graph[V][V] =   {  {0, 2, 0, 6, 0},
                           {2, 0, 3, 8, 5},
                           {0, 3, 0, 0, 7},
                           {6, 8, 0, 0, 9},
                           {0, 5, 7, 9, 0}};

    primeMst(graph);
    return 0;
}