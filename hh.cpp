#include<iostream>
#include<limits.h>
#define V 8

int minkey(int key[], bool setmst[]) {
    int min = INT_MAX, min_val;
    for (int v = 0; v < V; v++) {
        if (setmst[v] == false && key[v] < min) {
            min = key[v];
            min_val = v;
        }
    }
    return min_val;
}


void print(int parent[],int graph[V][V]){
    int tp=0;
for(int i=1;i<V;i++){
  std::cout<<parent[i]<<"-"<<i<<"  "<<graph[i][parent[i]]<<"\n"; 
  tp+=graph[i][parent[i]];
}
std::cout<<"min"<<tp;
}


void Prime(int graph[V][V]){
   int parent[V];
   int key[V];
   bool setmst[V];

   for(int i=0;i<V-1;i++){
    key[i]=INT_MAX;
    setmst[i]=false;
   }

   key[0]=0;
   parent[0]=-1;
   for(int c=0;c<V;c++){
   int u=minkey(key,setmst);
   setmst[u]=true;
   for(int v=0;v<V;v++){
    if(graph[u][v]&&setmst[v]==false&&graph[u][v]<key[v]){
        key[v]=graph[u][v];
        parent[v]=u;

    }
   }

   }
   print(parent,graph);

}




int main(){
 int graph[V][V]={
       {0, 4, 0, 8, 2, 0, 0, 0},
        {4, 0, 8, 10, 0, 0, 0, 0},
        {0, 8, 0, 11, 0, 0, 0, 0},
        {8, 10, 11, 0, 5, 0, 11, 0},
        {2, 0, 0, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 2},
        {0, 0, 0, 11, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 0}
 };

  Prime(graph);



}