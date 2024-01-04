#include<bits/stdc++.h>
using namespace std;

int V, E;
int parent[100];
int weight[100][100];

int find(int i) {
    while(parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void Union(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void Krush() {
    int min_cost = 0;
    int edc = 0;
    while (edc < V - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(i) != find(j) && weight[i][j] < min) {
                    min = weight[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        Union(a, b);
        cout << "edges count = " << edc << "(" << a << ' ' << b << ")" << " cost: " << min << endl;
        min_cost += min;
        edc++;
    }
    cout << "min cost = " << min_cost;
}

int main() {
    // Direct input for demonstration
    V = 5;
    E = 7;

    // Edge weights (m, n, w)
    int edges[][3] = {{0, 1, 2}, {6, 2, 3}, {2, 3, 1}, {3, 0, 4}, {0, 2, 5}, {1, 4, 6}, {3, 4, 2}};

    for (int j = 0; j < E; j++) {
        int m = edges[j][0];
        int n = edges[j][1];
        int w = edges[j][2];
        weight[m][n] = weight[n][m] = w;
    }

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    Krush();
    return 0;
}
