#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the parent of a vertex in the disjoint set
int find(vector<int> &parent, int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return find(parent, parent[vertex]);
}

// Union of two sets
void unionSets(vector<int> &parent, int x, int y) {
    int xParent = find(parent, x);
    int yParent = find(parent, y);
    parent[xParent] = yParent;
}

// Kruskal's algorithm to find the minimum spanning tree
void kruskalMST(int V, int E, vector<vector<int>> &edges) {
    // Sort the edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];
    });

    // Create a vector to store the parent of each vertex
    vector<int> parent(V, -1);

    for (const vector<int> &edge : edges) {
        int src = edge[0];
        int dest = edge[1];
        int weight = edge[2];

        int srcParent = find(parent, src);
        int destParent = find(parent, dest);

        // If including this edge does not cause a cycle, include it in the MST
        if (srcParent != destParent) {
            cout << src << " - " << dest << " : " << weight << endl;
            unionSets(parent, srcParent, destParent);
        }
    }
}

int main() {
    // Example usage
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    // Find and print the minimum spanning tree
    kruskalMST(V, E, edges);

    return 0;
}
