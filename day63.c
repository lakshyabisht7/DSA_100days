/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list
int adj[MAX][MAX];
int size[MAX];     // number of neighbors
int visited[MAX];

// DFS function
void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for(int i = 0; i < size[node]; i++) {
        int next = adj[node][i];

        if(!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 0; i < n; i++) {
        size[i] = 0;
        visited[i] = 0;
    }

    int u, v;

    // input edges
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // undirected graph
        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int s;
    scanf("%d", &s); // starting node

    dfs(s);

    return 0;
}