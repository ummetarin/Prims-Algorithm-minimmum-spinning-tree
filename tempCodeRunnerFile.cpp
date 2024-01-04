#include<iostream>
#include<limits.h>
#define V 8

//to find the low value from grpah

int Find_min(int key[],bool setmin[]){
   int min_value=INT_MAX,min_ind;
   for(int v=0;v<V;v++){
    if( !setmin[v]&&key[v]<min_value){
          key[v]=min_value;
          min_ind=v;
    }
   }
   return min_ind;

}


void print(int parent[],int graph[V][V]){
    int tp=0;
for(int i=1;i<V;i++){
    std::cout<<parent[i]<<"-"<<i<<"  "<<graph[i][parent[i]]<<'\n';
    tp+=graph[i][parent[i]];
}
std::cout<<"total price "<<tp;


}

void Prime(int graph[V][V]){
int parent[V]={-1};
int key[V];
bool setmin[V]={false};
key[0]=0;

for(int i=0;i<V-1;i++){
int u=Find_min(key,setmin);
setmin[u]=true;
for(int v=0;v<V;v++){
    if(graph[u][v]&&!setmin[v]&&key[v]<graph[u][v]){
        key[v]=graph[u][v];
        parent[v]=u;
    }
}
}
print(parent,graph);
}


int main(){

int graph[V][V]={

    {0,4,0,8,2,0,0,0},
    {4,0,8,10,0,0,0,0},
    {0,8,0,11,0,0,0,0},
    {8,10,11,0,5,0,11,0},
    {2,0,0,5,0,0,0,0},
    {0,0,0,0,0,0,1,2},
    
};

     Prime(graph);
    return 0;




}