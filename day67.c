//Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int node, int n) {
    visited[node] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }

    // push after visiting all neighbors
    stack[++top] = node;
}

void topoSort(int n) {
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, n);
        }
    }

    // print in reverse order of stack
    while(top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // input edges (DIRECTED)
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topoSort(n);

    return 0;
}