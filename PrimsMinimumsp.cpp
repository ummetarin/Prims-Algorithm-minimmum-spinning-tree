#include<iostream>>
#include<limits.h>
#define V 5

int minKey(int key[],bool setKey[]){
    int min_value=INT_MAX;
    int min_index;

    // v=all vertex

    for(int v=0;v<V;v++){
      if(!setKey&&key[v]<min_value){
        min_value=key[v];
        min_index=v;

      }

    }
    return min_index;

    
}


int main(){







}
