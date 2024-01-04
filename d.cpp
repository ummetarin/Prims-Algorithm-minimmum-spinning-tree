#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int,pair<int,int>>Edge;

int find(int vertex,vector<int>&parent){
  if(parent[vertex]==-1){
    return vertex;
  }
  return (parent[vertex],parent);
}

void unio(int x,int y,vector<int>&parent){
  int xset=find(x,parent)
  int yset=find(y,parent)
  parent[xset]=yset;
}

int krush(vetor<Edge>&ed,int vertex){
sort(ed.begin(),ed.end());
vector<int>parent(vertex,-1);
cout<<"mini  "<<endl;
for(const Edge & ed:ed){
  int u=ed.second.first
  int v=ed.second.second
  int we=ed.first
  int uset=find(u,parent);
  int vset=find(v,parent);
  if(uset!=vset){
    cout<<u<<"-"<<v<<" "<<we;
    unio(uset,vset,parent);
  }
}


int main(){
  vector<Edge>ed={
    {2,{4,5}},
    {4,{6,7}}
  }
  int vertex=2;
  krush(ed,vertex);
}
}
