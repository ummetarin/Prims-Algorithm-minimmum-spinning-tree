#include<iostream>
#include<limits.h>
#define V 8

int minkey(int key[], bool setkey[]) {
    int min = INT_MAX, min_ind;
    for (int v = 0; v < V; v++) {
        if (setkey[v] == false && key[v] < min) {
            min = key[v];
            min_ind = v;
        }
    }
    return min_ind;
}

void print(int parent[], int graph[V][V]) {
    int tp=0;
    for (int i = 1; i < V; i++) {
        std::cout << parent[i] << " - " << i << "  " << graph[i][parent[i]] << std::endl;
        tp+=graph[i][parent[i]];
    }
    std::cout<<"tp = "<<tp;
}

void Prime(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool setkey[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        setkey[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minkey(key, setkey);
        setkey[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && setkey[v] == false && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    print(parent, graph);
}

int main() {
    int graph[V][V] = {
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
    return 0;
}
